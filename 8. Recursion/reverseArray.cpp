#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void usingloop(int a[], int n)
{

    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        swap(a[l], a[r]);
        l++;
        r--;
    }
}

void usingrecursion(int i, int a[], int n)
{
    if (i >= n / 2)
    {
        return;
    }
    swap(a[i], a[n - i - 1]);
    usingrecursion(i + 1, a, n);
}

// vector<int> reverseArray(int n, vector<int> &nums)

// {

//     if (n == 0)
//     {

//         return {};
//     }
//     vector<int> v = reverseArray(n - 1, nums);

//     v.push_back(nums[nums.size() - n]);

//     return v;
// }

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Reverse Array Using LOOPS
    // reverseArrayusingloop(arr, n);

    // Reverse Array Using Recursion
    usingrecursion(0, arr, n);
    printArray(arr, n);
    return 0;
}