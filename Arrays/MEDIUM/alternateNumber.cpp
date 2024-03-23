#include <bits/stdc++.h>

using namespace std;

vector<int> alternateNumber(vector<int> &a, int n)
{
    // brut force solution
    // O(N) + O(N/2) time complexity
    // O(N) space complexity
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

    // OPTIMAL SOLUTION

    // vector<int> ans(n, 0);
    // int posIndex = 0;
    // int negIndex = 1;

    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] < 0)
    //     {
    //         ans[negIndex] = a[i];
    //         negIndex += 2;
    //     }
    //     else
    //     {
    //         ans[posIndex] = a[i];
    //         posIndex += 2;
    //     }
    // }
    // return ans;

    // variant 2 where if any of the positive and negative numbers are left , then add them at the end wihtout altering the order.

    // Optimal solution by following Brut force solution
    // TIME- O(N) + O(N)
    vector<int> pos, neg;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            pos.push_back(a[i]);
        }
        else
        {

            neg.push_back(a[i]);
        }
    }

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            a[index] = pos[i];
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            a[index] = neg[i];
        }
    }
    return a;
}
int main()
{
    vector<int> arr = {1, 2, -3, -1, -2, 3};
    int n = arr.size();

    alternateNumber(arr, n);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}