#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> &arr)
{
    int N = arr.size();
    int n = arr.size() - 1;
    // Brut Force
    // TC = O(N^2) SC = O(1)

    // bool flag = 0;
    // for (int i = 1; i <= arr.size(); i++)
    // {
    //     flag = 0;
    //     for (int j = 0; j < arr.size() - 1; j++)
    //     {
    //         if (arr[j] == i)
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 0)
    //     {
    //         return i;
    //     }
    // }

    // Using Hashing
    // TC = O(N)  SC = O(N + 1)

    // int n = arr.size();
    // int hash[n + 1] = {0};

    // for (int i = 0; i < n; i++)
    // {
    //     hash[arr[i]]++;
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (hash[i] == 0)
    //         return i;
    // }

    // OPTIMAL APPROACH
    int xor1 = 0;
    int xor2 = 0;

    for (int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ N;

    return (xor1 ^ xor2);
}
int main()
{
    vector<int> arr = {1, 2, 4, 5};
    int ans = missingNumber(arr);
    cout << ans;
    return 0;
}