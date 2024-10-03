// LEETCODE - 229

#include <bits/stdc++.h>

using namespace std;

vector<int> majElement(vector<int> &v, int N)
{
    //  BETTER CASE
    //  TC: O(N) SC: O(N)
    // vector<int> ans;
    // map<int, int> mpp;
    // int mini = (int)(N / 3) + 1;

    // for (int i = 0; i < N; i++)
    // {
    //     mpp[v[i]]++;
    //     if (mpp[v[i]] == mini)
    //     {
    //         ans.push_back(v[i]);
    //     }
    //     if (ans.size() == 2)
    //         break;
    // }
    // sort(ans.begin(), ans.end());
    // return ans;

    // OPTIMAL SOLUTION
    // TC: O(N) SC: O(1)

    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        if (cnt1 == 0 && ele2 != v[i])
        {
            cnt1 = 1;
            ele1 = v[i];
        }
        else if (cnt2 == 0 && ele1 != v[i])
        {
            cnt2 = 1;
            ele2 = v[i];
        }
        else if (ele1 == v[i])
            cnt1++;
        else if (ele2 == v[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < N; i++)
    {
        if (ele1 == v[i])
            cnt1++;
        if (ele2 == v[i])
            cnt2++;
    }

    int mini = (int)(N / 3) + 1;
    if (cnt1 >= mini)
        ans.push_back(ele1);
    if (cnt2 >= mini)
        ans.push_back(ele2);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 2};
    int N = arr.size();
    vector<int> ans = majElement(arr, N);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}