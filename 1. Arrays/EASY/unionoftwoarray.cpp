

#include <bits/stdc++.h>

using namespace std;

vector<int> unionOftwoArray(vector<int> &a, vector<int> &b)
{

    // BRUT FORCE
    // If all the elements are unique then
    // TC: ((n1 + n2)*LOG(N))
    // SC: WE ARE USING EXTRA VECTOR AND SET OF SIZE NO. OF UNIQUE ELEMENTS O(N)

    // int n1 = a.size();
    // int n2 = b.size();

    // vector<int> ans;
    // set<int> st;

    // for (auto it : a) // O(n1Log(N))
    // {
    //     st.insert(it);
    // }
    // for (auto it : b) // O(n2log(N))
    // {
    //     st.insert(it);
    // }

    // for (auto it : st)
    // {
    //     ans.push_back(it);
    // }

    // return ans;

    // OPTIMAL APPROACH
    // 2 pointer approach
    // EVERY TIME WE STORING UNIQUE ELEMENT AND UTILIZING SORTED PROPERTY 
    //  TC: O(N1 + N2) we are visiting every element at Once

    int n1 = a.size();
    int n2 = b.size();

    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (ans.size() == 0 ||
                ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 ||
                ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    while (j < n2)
    {
        if (ans.size() == 0 ||
            ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }
    while (i < n1)
    {
        if (ans.size() == 0 ||
            ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 6};
    vector<int> b = {2, 3, 5};

    vector<int> ans = unionOftwoArray(a, b);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}