#include <bits/stdc++.h>

using namespace std;



int Partition(int* Arr, int p, int r)
{
    int x = Arr[r];
    int i = p - 1;

    for (int j = p; j <= r; j++)
    {
        if (Arr[j] < x)
        {
            i++;
            swap(Arr[i], Arr[j]);
        }
    }

    swap(Arr[i+1], Arr[r]);
    return i + 1;
}


void QuickSort(int* Arr, int p, int r)
{
    if (p < r)
    {
        int q = Partition(Arr, p, r);
        QuickSort(Arr, p, q-1);
        QuickSort(Arr, q+1, r);
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

    QuickSort(A, 0, size - 1);

    cout << "\nSorted Array: \n";
    PrintArray(A, size);

    cout << "\n";

system("PAUSE");
return 0;
}