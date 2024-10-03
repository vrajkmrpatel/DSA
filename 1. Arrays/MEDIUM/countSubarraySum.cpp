#include <bits/stdc++.h>

using namespace std;

int countSubarraySum(vector<int> &arr, int k)
{
    int n = arr.size();
    map<int, int> mpp;
    mpp[0] = 1;
    int prefSum = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        prefSum += arr[i];
        int remove = prefSum - k;
        count += mpp[remove];
        mpp[prefSum] += 1;
    }
    return count;
}
int main()
{
    vector<int> arr{1, 2, 3, -3, 1, 1, 1, 4, 2, -3};

    int ans = countSubarraySum(arr, 3);
    cout << ans;
    return 0;
}