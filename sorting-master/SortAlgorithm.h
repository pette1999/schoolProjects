using namespace std;

template <class T>
class SortAlgorithm
{
    public:
        SortAlgorithm();
        ~SortAlgorithm();

        //https://www.geeksforgeeks.org/quick-sort/
        void quickSort(T* A, int low, int high);
        //https://www.geeksforgeeks.org/insertion-sort/
        void insertionSort(T* A, int length);
        //https://www.geeksforgeeks.org/bubble-sort/
        void bubbleSort(T* A, int length);
        //https://www.geeksforgeeks.org/cycle-sort/
        void cycleSort(T* A, int length);

        void swap(T *a, T *b);
        void swapNum(T a, T b);
        int partition(T *A, int low, int high);

        void printQuicksort(T *A, int size);
        void printInsertionsort(T *A, int size);
        void printBubblesort(T *A, int size);
        void printCyclesort(T *A, int size);
};

template <class T>
SortAlgorithm<T>::SortAlgorithm()
{

}

template <class T>
SortAlgorithm<T>::~SortAlgorithm()
{

}

// A utility function to swap two elements
template <class T>
void SortAlgorithm<T>::swap(T *a, T *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

template <class T>
void SortAlgorithm<T>::swapNum(T a, T b)
{
    int t = a;
    a = b;
    b = t;
}

/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
template <class T>
int SortAlgorithm<T>::partition(T *A, int low, int high)
{
    int pivot = A[high]; //pivot
    int i = low-1; // index of the samller element

    for(int j = low; j <= high-1; j++)
    {
        if(A[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    return (i+1);
}

template <class T>
void SortAlgorithm<T>::quickSort(T* A, int low, int high)
{
    if(low < high)
    {
        /* p is partitioning index, arr[p] is now  
        at right place */
        int p = partition(A, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(A, low, p-1);
        quickSort(A, p+1, high);
    }
}

template <class T>
void SortAlgorithm<T>::insertionSort(T *A, int length)
{
    int i;
    int key;
    int j;
    for (int i = 1; i < length; i++)
    {
        key = A[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j -= 1;
        }
        A[j + 1] = key;
    }
}

// A function to implement bubble sort
template <class T>
void SortAlgorithm<T>::bubbleSort(T* A, int length)
{
    int i;
    int j;
    for(i=0; i<length-1; i++)
    {
        for(j=0; j<length-i-1; j++)
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
            }
        }
    }
}

template <class T>
void SortAlgorithm<T>::cycleSort(T *A, int length)
{
    // count number of memory writes
    int writes = 0;

    // traverse array elements and put it to on
    // the right place
    for(int cycle_start = 0; cycle_start <= length-2; cycle_start++)
    {
        // initialize item as starting point
        T item = A[cycle_start];

        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
        for(int i=cycle_start+1; i<length; i++)
        {
            if(A[i] < item)
            {
                pos++;
            }
        }

        // If item is already in correct position
        if(pos == cycle_start)
        {
            continue;
        }

        // ignore all duplicate  elements
        while(item == A[pos])
        {
            pos += 1;
        }

        // put the item to it's right position
        if(pos != cycle_start)
        {
            swapNum(item, A[pos]);
            writes++;
        }

        // Rotate rest of the cycle
        while(pos != cycle_start)
        {
            pos = cycle_start;

            // Find position where we put the element
            for(int i = cycle_start+1; i<length; i++)
            {
                if(A[i] < item)
                {
                    pos += 1;
                }
            }

            // ignore all duplicate  elements
            while(item == A[pos])
            {
                pos += 1;
            }

            // put the item to it's right position
            if(item != A[pos])
            {
                swapNum(item, A[pos]);
                writes++;
            }
        }
    }
}

template <class T>
void SortAlgorithm<T>::printQuicksort(T *A, int size)
{
    int i;
    for(int i=0; i<size; i++)
    {
        cout << A[i] << " ";//in order to print the array on the same line
    }
    cout << endl;
}

template <class T>
void SortAlgorithm<T>::printInsertionsort(T *A, int size)
{
    int i;
    for(i = 0; i<size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
void SortAlgorithm<T>::printBubblesort(T *A, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
void SortAlgorithm<T>::printCyclesort(T *A, int size)
{
    for(int i=0; i<size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}