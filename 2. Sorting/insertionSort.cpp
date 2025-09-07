// LOGIC: EVERY TIME WE PICK UP AN ELEMENT AND PLACE IT AT IT'S CORRECT POSSITION
// TIME COMPLEXITY:
// WORST CASE: O(N^2)-> WHEN ELEMENTS ARE IN DECENDING ORDER
// LIKE [5, 4, 3, 2, 1] LOOPS RUNS N(N-1)/2 TIMES
// AVERAGE CASE: O(N^2)
// BEST CASE: O(N)-> WHEN ELEMENTS ARE IN ASCENDING ORDER
// NO SWAPS HAPPENS IN INNER LOOP
                                             
#include <bits/stdc++.h>

using namespace std;

void insertionSort(int a[], int n)
{
    cout << "Insertion Sort\n";
    for (int i = 0; i < n; i++)
    {

        int j = i;
        while (j > 0 && a[j - 1] > a[j])
        {
            swap(a[j - 1], a[j]);
            j--;
            // cout << "swap\n";
        }
    }
}

int main()
{
    // Using Array
    // int arr[] = {13, 46, 24, 52, 9};
    // int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {5, 4, 3, 2, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}