# include "sharedMemory.h"
# include <iostream>
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

// handle user's singal command while running
void signal_handler(int sig)
{
  shm_unlink(name);
  cout << "\nExiting" << endl;
  exit(1);
}

extern unsigned int ip_checksum(unsigned char *data, int length);

int main(int argc, char *argv[])
{
  int i, shm_fd;
  int nbytes;
  void *ptr;

  item next_produced;

  unsigned short cksum;

  // got help from Gabriela this part
  unsigned char *buffer; //change item buffer

  struct sigaction act;
  act.sa_handler = signal_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;

  if (argc < 3)
  {
    printf("Usage: %s <nbytes> \n", argv[0]);
    return 0;
  }

  // get the input argument shared memory name
  name = argv[1];
  // define how much data should be placed into the shared memory
  nbytes = atoi(argv[2]);

  /* create the shared memory object */
  shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

  if (shm_fd == -1)
  {
    perror("Error creating shared memory");
    return -1;
  }

  /* configure the size of the shared memory object */
  ftruncate(shm_fd, MMAP_SIZE);

  /* memory map the shared memory object */
  ptr = mmap(0, MMAP_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

  buffer = (unsigned char *)ptr;
  next_produced.item_no = 0; //set the buffer count to 0

  while (true)
  {
    /* produce an item in next_produced */
    /* 1. Increment the buffer count (item_no)  */
    next_produced.item_no++;

    for (i = 0; i < nbytes; i++)
    {
      /* 3. Generate the payload data             */
      next_produced.payload[i] = (unsigned char)rand() % 256;
    }

    /* 2. Calculate the 16-bit checksum (cksum) */
    next_produced.cksum = (unsigned short)ip_checksum(&next_produced.payload[0], PAYLOAD_SIZE);

    while (((in + 1) % BUFFER_SIZE) == out)
      usleep(150000);             /* do nothing but sleep for 1 second */

    memcpy((void *)&buffer_item[in], &next_produced.cksum, sizeof(next_produced.cksum));
    buffer_item[in] = next_produced; /* store next_produced into shared buffer */
    in = (in + 1) % BUFFER_SIZE;

    sigaction(SIGINT, &act, 0);
  }

  return 0;
}