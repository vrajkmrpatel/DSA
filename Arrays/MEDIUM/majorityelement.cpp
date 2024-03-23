#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &arr, int n)
{

    // BRUTE
    // time - O(N^2)
    // space - O(1)
    // for (int i = 0; i < n; i++)
    // {
    //     int cnt = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             cnt++;
    //         }
    //     }

    //     if (cnt > n / 2)
    //     {
    //         return arr[i];
    //     }
    // }
    // return -1;

    // Hashmap

    // map<int, int> mp;

    // for (int i = 0; i < n; i++)
    // {
    //     mp[arr[i]]++;
    // }
    // for (auto it : mp)
    // {
    //     if (it.second > n / 2)
    //     {
    //         return it.first;
    //     }
    // }
    // return -1;

    // Optimal Solution
    // MOORE'S VOTING ALGORITHM

    int cnt = 0;
    int ele;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            ele = arr[i];
        }
        else if (ele == arr[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    int cnt1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (ele == arr[i])
        {
            cnt1++;
        }
    }
    if (cnt1 > n / 2)
    {
        return ele;
    }
    return -1;
}
int main()
{
    vector<int> arr = {-53, 56, 56, 52, 56, 54, 56};

    int n = arr.size();

    int ans = majorityElement(arr, n);

    cout << ans;
    return 0;
}