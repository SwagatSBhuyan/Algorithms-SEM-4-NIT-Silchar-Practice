#include <bits/stdc++.h>

using namespace std;


void MaxHeapify(int* A, int i, int heapsize)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;

    if (l < heapsize && A[l] > A[largest])
        largest = l;
    if (r < heapsize && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        swap(A[i], A[largest]);
        MaxHeapify(A, largest, heapsize);
    }
}

void BuildMaxHeap(int* A, int heapsize)
{
    for (int i = (heapsize/2) - 1; i >= 0; i--)
        MaxHeapify(A, i, heapsize);
}

void HeapSort(int* A, int size)
{
    int heapsize = size;
    BuildMaxHeap(A, heapsize);
    for (int i = size-1; i > 0; i--)
    {
        swap(A[0], A[i]);
        heapsize--;
        MaxHeapify(A, 0, heapsize);
    }
}

void RandomArrayGenerator(int* Arr, int size, int lim)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
        Arr[i] = rand() % (lim + 1);
}

void PrintArray(int* Arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << Arr[i] << "  ";
}


int main()
{
system("CLS");

    srand(time(0));
    int A[1000], size = 10, lim = 10;
    //int A[] = {4, 8, 3, 90, 65, 12, 0, 69, 89};
    //cout << sizeof(A);

    cout << "\nEnter Array Size: "; cin >> size;
    cout << "\nEnter Array Content MAX_RANGE: "; cin >> lim;
    RandomArrayGenerator(A, size, lim);

    cout << "\nOriginal Array: \n";
    PrintArray(A, size);

    HeapSort(A, size);

    cout << "\nSorted Array: \n";
    PrintArray(A, size);

    cout << "\n\n";

system("PAUSE");
return 0;
}