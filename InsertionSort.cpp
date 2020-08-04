#include <bits/stdc++.h>

using namespace std;

void InsertionSort(int* Arr, int size)
{
    for (int j = 1; j < size; j++)
    {
        int key = Arr[j];
        int i = j - 1;
        while (i >= 0 && Arr[i] > key)
            Arr[i+1] = Arr[i--];
        Arr[i+1] = key;
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

    InsertionSort(A, size);

    cout << "\nSorted Array: \n";
    PrintArray(A, size);

    cout << "\n";

system("PAUSE");
return 0;
}