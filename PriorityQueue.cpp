#include <bits/stdc++.h>

using namespace std;


int queuesize = 0;

int parent(int i)
{
    return (i - 1) / 2;
}

void MaxHeapify(int* A, int i, int heapsize)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i ;

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

void ModifyKey(int* Q, int i, int key)
{
    Q[i] = key;
    while (Q[parent(i)] < Q[i] && parent(i) >= 0)
    {
        swap(Q[i], Q[parent(i)]);
        i = parent(i);
    }
}

void Insert(int* Q, int key)
{
    queuesize++;
    Q[queuesize] = INT_MIN;
    ModifyKey(Q, queuesize-1, key);
}

int ExtractKey(int* Q)
{
    if (queuesize <= 0)
    {
        cout << "UNDERFLOW...";
        system("PAUSE");
        exit(0);
    }

    int max = Q[0];
    Q[0] = Q[queuesize - 1];
    queuesize--;
    MaxHeapify(Q, 0, queuesize);
    
    return max;
}

void RandomPriorityQueueGenerator(int* Arr, int size, int lim)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        int item = rand() % (lim + 1);
        Insert(Arr, item);
    }
}

void PrintPriorityQueue(int* Arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << Arr[i] << "  ";
}


int main()
{
system("CLS");

    srand(time(0));
    int Q[1000], size = 10, lim = 10, choice = 1, item = 0;
    //int A[] = {4, 8, 3, 90, 65, 12, 0, 69, 89};
    //cout << sizeof(A);

    cout << "\nEnter Initial Priority Queue Size: "; cin >> size;
    cout << "\nEnter Priority Queue Content MAX_RANGE: "; cin >> lim;
    RandomPriorityQueueGenerator(Q, size, lim);

    system("CLS"); 

    while (choice != 3)
    {
        system("CLS");
        cout << "\nPriority Queue so far..... \n";
        PrintPriorityQueue(Q, queuesize);
        
        cout << "\nPRIORITY QUEUE OPERATIONS: ";
        cout << "\n1. Insert Item into Priority Queue";
        cout << "\n2. Extract max from Priority Queue";
        cout << "\n3. Exit.";
        cout << "\nCHOOSE: "; cin >> choice;

        if (choice == 1)
        {
            cout << "\nEnter item to insert: ";
            cin >> item;
            Insert(Q, item);
        }
        else if (choice == 2)
        {
            int ext = ExtractKey(Q);
            cout << "\nExtracted item from Priority Queue: " << ext << "\n\n";
        }
        else if (choice == 3)
        {
            system("PAUSE");
            exit(0);
        }
        else
        {
            cout << "\nINVALID INPUT......";
            continue;
        }  
        system("PAUSE"); 
    }
    cout << "\n\n";

system("PAUSE");
return 0;
}