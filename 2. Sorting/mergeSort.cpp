// LOGIC: here we blindly divide the array using mid, and solve each subproblem then combine the array using MERGE Algorithm

// TC EACH RESURSIVE CALL TAKES LOG(N) TIME
// EACH MERGE ALGORITHM TAKES O(N) TIME
//  TOTAL TC: O(N*LOG(N))

#include <bits/stdc++.h>

using namespace std;

void mergeAlgo(vector<int> &arr, int low, int mid, int high)
{

    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {

        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {

        arr[i] = temp[i - low];
    }
    // cout << "complete" << endl;
}
void mergeSort(vector<int> &arr, int low, int high)
{

    if (low == high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeAlgo(arr, low, mid, high);
}

int main()
{
    // Using Array
    // int arr[] = {13, 46, 24, 52, 9};
    // int arr[] = {1, 2, 3, 4, 5};
    cout << "Merge Sort\n";
    vector<int> arr = {13, 46, 24, 52, 9};

    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}