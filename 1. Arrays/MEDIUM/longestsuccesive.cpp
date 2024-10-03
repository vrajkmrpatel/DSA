#include <bits/stdc++.h>

using namespace std;

int longestConsecutinve(vector<int> &arr)
{

    // BETTER SOLUTION
    // int n = arr.size();
    // sort(arr.begin(), arr.end());

    // int count = 0;
    // int longest = 1;
    // int lastSmaller = INT_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] - 1 == arr[i + 1] - 1)
    //     {
    //         count += 1;
    //         lastSmaller = arr[i];
    //     }
    //     else if (arr[i] != lastSmaller)
    //     {
    //         count = 1;
    //         lastSmaller = arr[i];
    //     }
    //     longest = max(longest, count);
    // }
    // return longest;

    // OPTIMAL SOLUTION
    int n = arr.size();
    int longest = 1;
    if (n == 0)
        return 0;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                count += 1;
            }
            longest = max(longest, count);
        }
    }
    return longest;

    
}
int main()
{
    vector<int> arr = {1, 9, 3, 10, 4, 20, 2};

    int ans = longestConsecutinve(arr);

    cout << ans;
    return 0;
}