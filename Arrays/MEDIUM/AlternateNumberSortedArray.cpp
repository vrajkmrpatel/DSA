// GFG PROBLEM DIFFERENT THAN CODE STUDIO

#include <bits/stdc++.h>

using namespace std;

void AltetnateNumberSortedArray(vector<int> &arr, int n)
{

    // int left = 0;
    // int right = n - 1;
    // vector<int> ans(n, 0);
    // int i = 0;
    // while (left <= right)
    // {
    //     ans[i++] = arr[right--];
    //     ans[i++] = arr[left++];
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = ans[i];
    // }

    // OPTIMAL SOLUTION WITHOUT USING EXTRA SPACE
    int j = n - 1;
    int i = 0;
    int maxi = arr[n - 1] + 1;

    for (i = 0; i < n; i += 2)
    {
        arr[i] = arr[i] + (arr[j] % maxi) * maxi;
        j--;
    }
    j = 0;
    for (int i = 1; i < n; i += 2)
    {
        arr[i] = arr[i] + (arr[j] % maxi) * maxi;
        j++;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] /= maxi;
    }
}
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int n = arr.size();

    AltetnateNumberSortedArray(arr, n);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}