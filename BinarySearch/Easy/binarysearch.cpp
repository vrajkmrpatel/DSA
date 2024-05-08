#include <bits/stdc++.h>

using namespace std;

int BinarySearch(vector<int> &arr, int low, int high, int target)
{
    // ITERATIVE METHOD

    // int mid = low + (high - low) / 2;

    // while (low <= high)
    // {
    //     if (arr[mid] == target)
    //     {
    //         return mid;
    //     }
    //     else if (arr[mid] > target)
    //     {
    //         high = mid - 1;
    //     }
    //     else
    //     {
    //         low = mid + 1;
    //     }
    // }
    // return -1;

    // USING RECURSION
    int mid = low + (high - low) / 2;

    if (low > high)
        return -1;
    if (arr[mid] == target)
        return mid;
    else if (target > arr[mid])
    {
        return BinarySearch(arr, mid + 1, high, target);
    }
    return BinarySearch(arr, low, mid - 1, target);
}
int main()
{
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};

    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = BinarySearch(arr, low, high, 6);

    cout << ans << endl;

    // Using Recursion

    return 0;
}