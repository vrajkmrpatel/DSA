#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{

    int i = low;
    int j = high;
    int pivot = arr[low];

    while (i < j)
    {

        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);

    return j;
}
void quickSort(vector<int> &arr, int low, int high)
{

    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{

    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}