

#include <bits/stdc++.h>

using namespace std;

vector<int> intersectOfTwoArray(vector<int> &a, vector<int> &b)
{

    // BRUT FORCE
    // TC: O(N*M)
    // sc: O(min(N,M))

    // int n = a.size();
    // int m = b.size();

    // int vis[m] = {0};
    // vector<int> ans;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (a[i] == b[j] && vis[j] == 0)
    //         {
    //             ans.push_back(a[i]);
    //             vis[j] = 1;
    //             break;
    //         }
    //         if (b[j] > a[i])
    //             break;
    //     }
    // }

    // return ans;

    // OPTIMAL APPROACH -> TWO POINTER APPROACH
    // TC: O(N + M) worst case if every time we increase i and j iteratively (first two condition)
    // SC: O(1)
    int n = a.size();
    int m = b.size();

    vector<int> ans;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (a[i] > b[j])
        {
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {3, 4, 5, 6, 7};

    vector<int> ans = intersectOfTwoArray(a, b);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}