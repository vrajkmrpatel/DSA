#include <bits/stdc++.h>

using namespace std;

int getPairsCount(vector<int> &arr, int n, int k)
{
    // code here
    // // BRUT FORCE SOLUTION
    // // TIME : O(N^2)
    // // SPACE: O(1)

    // VARIANT-1
    // int count = 0;
    // int sum = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         sum = arr[i] + arr[j];
    //         if (sum == k)
    //         {
    //             // cout << "YES";
    //             count++;
    //         }
    //     }
    // }
    // // cout << "NO";
    // return count;

    // // VARIANT - 2
    // int count = 0;
    // int sum = 0;
    // vector<int> ans;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         sum = arr[i] + arr[j];
    //         if (sum == k)
    //         {
    //             ans.push_back(i);
    //             ans.push_back(j);
    //             return ans;
    //         }
    //     }
    // }
    // // cout << "NO";
    // return {-1, -1};

    // BETTER APPROACH USING HASHMAP

    map<int, int> mp;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int more = k - num;

        if (mp.find(more) != mp.end())
        {
            count++;
        }
        if (mp.find(num) == mp.end())
        {
            mp[num] = i;
        }
    }
    return count;

    // OPTIMAL TWO POINTER
    // TIME - O(N + N*LOGN)
    // SPACE - O(1)

    // sort(arr.begin(), arr.end());

    // int left = 0;
    // int right = n - 1;
    // while (left < right)
    // {

    //     int sum = arr[left] + arr[right];
    //     if (sum == target)
    //     {
    //         return "YES";
    //     }
    //     else if (sum < target)
    //         left++;
    //     else
    //         right--;
    // }

    // return "NO";
}
int main()
{
    vector<int> arr = {1, 5, 5, 5, 5, 7};
    // int size = sizeof(arr) / sizeof(arr[0]);
    int size = arr.size();

    int ans = getPairsCount(arr, size, 10);
    cout << ans;
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    return 0;
}