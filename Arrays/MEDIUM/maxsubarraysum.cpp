#include <bits/stdc++.h>

using namespace std;
int maxsubarraysum(vector<int> &arr, int n)
{

    // BRUT FORCE SOLUTION
    // TIME - O(N^2)

    // int maxi = INT_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     // int newSum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];
    //         // newSum += arr[j];
    //         // if (newSum > sum)
    //         // {
    //         //     sum = newSum;
    //         // }
    //         maxi = max(sum, maxi);
    //     }
    // }
    // return maxi;

    // OPTIMAL SOLUTION
    // KADANE'S ALGORITHM

    // time - O(N) linear time complexity
    // space - O(1)
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0;
    int ansStart, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << "Subarray is: [ ";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
    if (maxi < 0)
    {
        maxi = 0;
    }
    return maxi;
}
int main()
{
    vector<int> v = {-7, -8, -16, -4, -8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10};
    int n = v.size();

    int sum = maxsubarraysum(v, n);
    cout << "MAXIMUM SUBARRAY SUM IS: " << sum;
    return 0;
}