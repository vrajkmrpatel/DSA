#include <bits/stdc++.h>

using namespace std;

vector<int> removeDuplicates(vector<int> &arr)
{
      int n = arr.size();

      // using set
      // set<int> st;
      // for (auto it : arr)
      // {
      //       st.insert(it);
      // }

      // vector<int> ans;
      // for (auto s : st)
      // {
      //       ans.push_back(s);
      // }

      // return ans;

      // order must remain same
      // we can use hashmap

      unordered_map<int, bool> mp;
      vector<int> ans;
      for (auto current : arr)
      {
            if (mp.find(current) == mp.end())
            {
                  mp[current] = true;
                  ans.push_back(current);
            }
      }
      return ans;
}
int main()
{
      vector<int> arr = {8, 7, 7, 6, 6, 5};

      vector<int> ans = removeDuplicates(arr);

      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}