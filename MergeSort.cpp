#include <bits/stdc++.h>

using namespace std;


void Merge(int* Arr, int p, int q, int r)
{
    int i = 0, j = 0, k = 0;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[1000], R[1000];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    for (i = 0; i < n1; i++)
        L[i] = Arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = Arr[q + j + 1];

    i = 0, j = 0, k = p;
    while (i < n1  && j < n2)
    {
        if (L[i] <= R[j])
            Arr[k] = L[i++];
        else
            Arr[k] = R[j++];  
        k++;         
    }    
    while (i < n1) 
        Arr[k++] = L[i++]; 
    while (j < n2) 
        Arr[k++] = R[j++]; 

}


void MergeSort(int* Arr, int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r)/2);
        MergeSort(Arr, p, q);
        MergeSort(Arr, q+1, r);
        Merge(Arr, p, q, r);
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

    MergeSort(A, 0, size - 1);

    cout << "\nSorted Array: \n";
    PrintArray(A, size);

    cout << "\n";

system("PAUSE");
return 0;
}