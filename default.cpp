#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> alternateNumber(vector<int> &a, int n)
{
    // vector<int> pos, neg;

    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] > 0)
    //     {
    //         pos.push_back(a[i]);
    //     }
    //     else
    //     {
    //         neg.push_back(a[i]);
    //     }
    // }
    // for (int i = 0; i < n / 2; i++)
    // {
    //     a[2 * i] = pos[i];
    //     a[2 * i + 1] = neg[i];
    // }
    // return a;
    // return ans;
    // for (int i = 0; i < n; 2 * i)
    // {
    //     ans.push_back(pos[i]);
    // }
    // for (int i = 0; i < n; 2 * i + 1)
    // {
    //     ans.push_back(neg[i]);
    // }

    // // return ans;
    // for (auto it : a)
    // {
    //     cout << it << " ";
    // }

    vector<vector<int>> ans(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
    }
    // => != <= >= === 
}
int main()
{
    // vector<int> arr(5,0);
    // int n = arr.size();
    int n = 5;
    int arr[n] = {0};

    // alternateNumber(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}