#include <iostream>

using namespace std;

int reversearr(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        // swap 
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    printarr(arr, n);

    reversearr(arr, n);

    printarr(arr, n);
}