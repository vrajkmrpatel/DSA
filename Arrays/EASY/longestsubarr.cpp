#include <bits/stdc++.h>

using namespace std;

int longestSubarraySumK(vector<int> &arr, long long k)
{
    // Brut Force Approach
    // O(N^2)
    // int sum = 0;
    // int len = 0;
    // int n = arr.size();
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];
    //         if (sum == k)
    //             len = max(len, j - i + 1);
    //     }
    // }

    // return len;

    // Better Approach
    // TC:
    // map<long long, int> preSumMap;
    // long long sum = 0;
    // int maxLen = 0;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     sum += arr[i];

    //     if (sum == k)
    //     {
    //         maxLen = max(maxLen, i + 1);
    //     }
    //     int rem = sum - k;
    //     if (preSumMap.find(rem) != preSumMap.end())
    //     {
    //         int len = i - preSumMap[rem];
    //         maxLen = max(maxLen, len);
    //     }
    //     if (preSumMap.find(sum) == preSumMap.end())
    //     {
    //         preSumMap[sum] = i;
    //     }
    // }
    // return maxLen;

    // Optimal solution when there is only positive and zero element

    int left = 0, right = 0;
    int n = arr.size();
    long long sum = arr[0];
    int maxLen = 0;

    while (right < n)
    {

        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
            sum += arr[right];
    }
    return maxLen;
}
int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};

    int ans = longestSubarraySumK(arr, 3);
    cout << ans;
    return 0;
}