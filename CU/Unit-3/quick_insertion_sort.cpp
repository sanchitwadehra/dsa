// Quick and Insertion Sort
#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int l, int h)
{
    int piv = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] < piv)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quicksort(int arr[], int l, int h)
{
    if (l < h)
    {
        int piv = partition(arr, l, h);
        quicksort(arr, l, piv - 1);
        quicksort(arr, piv + 1, h);
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (i; i > 0; i--)
        {
            int j = i - 1;
            if (arr[j] < arr[i])
            {
                break;
            }
            if (arr[j] > arr[i])
            {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the length of array :- " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements into the array :- " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nSo the array you entered is :- " << endl;
    printArray(arr, n);
    cout << endl;
label_1:
    cout << "To sort by  1) quick sort or 2) insertion sort " << endl;
    int s;
    cin >> s;
    if (s == 1)
    {
        int carr[n];
        // Copying the Array
        for (int i = 0; i < n; i++)
        {
            carr[i] = arr[i];
        }
        quicksort(carr, 0, n - 1);
        cout << "Printing the sorted array :- " << endl;
        printArray(carr, n);
    }
    else if (s == 2)
    {
        int darr[n];
        // Copying the Array
        for (int i = 0; i < n; i++)
        {
            darr[i] = arr[i];
        }
        insertionSort(darr, n);
        cout << "Printing the sorted array :- " << endl;
        printArray(darr, n);
    }
    else
    {
        cout << "please enter a valid response" << endl;
        goto label_1;
    }
    return 0;
}