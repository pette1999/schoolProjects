#include "sharedMemory.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

using namespace std;

const char *name = "OS-IPC";

// handle user's singal command while running, so when user input control-c, it would say Exiting
void signal_handler(int sig)
{
  // remove a shared memory object
  shm_unlink(name);
  cout << "\nExiting" << endl;
  exit(1);
}

extern unsigned int ip_checksum(unsigned char *data, int length);

int main(int argc, char *argv[])
{
  int shm_fd;
  void *ptr;

  item next_consumed;
  unsigned short cksum1, cksum2;
  unsigned char *buffer; //change item buffer

  // change the action taken by a process on receipt of a specific signal
  struct sigaction act;
  // specifies the action to be associated with signum and may be SIG_DFL for the default action
  act.sa_handler = signal_handler;
  //initializes the signal set given by set to empty, with all signals excluded from the set
  sigemptyset(&act.sa_mask);
  //specifies a set of flags which modify the behavior of the signal
  act.sa_flags = 0;

  // check if the user input has at least 2 arguments
  if (argc < 2)
  {
    printf("Usage: %s <nbytes> \n", argv[0]);
    return -1;
  }

  // get the input argument shared memory name
  name = argv[1];
  /* create the shared memory object */
  shm_fd = shm_open(name, O_RDONLY, 0666);

  if (shm_fd == -1)
  {
    perror("Error creating shared memory");
    return -1;
  }

  /* configure the size of the shared memory object */
  ftruncate(shm_fd, MMAP_SIZE);

  /* memory map the shared memory object */
  ptr = mmap(0, MMAP_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

  buffer = (unsigned char *)ptr;
  cksum1 = (unsigned short)ip_checksum(&buffer[0], PAYLOAD_SIZE);

  cout << "size: " << sizeof(cksum1) << endl;
  in = sizeof(cksum1);

  int bufferCount = 0;

  while (true)
  {
    while (in == out)
    {
      usleep(150000); /* do nothing but sleep for 1 second */
      sigaction(SIGINT, &act, 0);
    }

    /* consume the item in next_consumed */
    /* 1. Check for no skipped buffers (item_no is contiguous) */
    if (bufferCount != next_consumed.item_no)
    {
      printf("Skipped buffers\n");
      return -1;
    }

    memcpy((void *)&cksum2, (void *)&buffer[PAYLOAD_SIZE], sizeof(unsigned short));
    next_consumed = buffer_item[out];
    out = (out + 1) % BUFFER_SIZE;

    /* configure the size of the shared memory object */
    ftruncate(shm_fd, MMAP_SIZE);

    /* memory map the shared memory object */
    ptr = mmap(0, MMAP_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    buffer = (unsigned char *)ptr;
    cksum1 = (unsigned short)ip_checksum(&buffer[0], PAYLOAD_SIZE);

    /* 2. Verify the calculated checksum matches what is stored in next_consumed */
    if (cksum1 != cksum2)
    {
      printf("Checksum mismatch: received 0x%x, expected 0x%x \n", cksum2, cksum1);
      break;
    }
    sigaction(SIGINT, &act, 0);
    bufferCount++;
    next_consumed.item_no++;
  }
  return 0;
}