#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
      // nums1 subset of nums2
      // n < m
      int n = nums1.size();
      int m = nums2.size();

      vector<int> ans(n, -1);
      // Brute force
      // for (int i = 0; i < n; i++)
      // {
      //       for (int j = 0; j < m; j++)
      //       {
      //             if (nums1[i] == nums2[j])
      //             {
      //                   for (int k = j + 1; k < m; k++)
      //                   {
      //                         if (nums2[k] > nums2[j])
      //                         {
      //                               ans[i] = nums2[k];
      //                               break;
      //                         }
      //                   }
      //                   break;
      //             }
      //       }
      // }
      // return ans;

      // Using Stack and Map
      stack<int> st;
      unordered_map<int, int> mpp;

      for (int i = m - 1; i >= 0; i--)
      {
            while(!st.empty() && st.top() <= nums2[i])
            {
                  st.pop();
            }

            if(!st.empty())
            {
                  mpp[nums2[i]] = st.top();
            }
            else {
                  mpp[nums2[i]] = -1;
            }
            st.push(nums2[i]);
      }
      
      for(int i = 0; i <n; i++)
      {
            if(mpp.find(nums1[i]) != mpp.end())
            {
                  ans[i] = mpp[nums1[i]];
            }
      }

      return ans;
}

int main()
{
      vector<int> nums1 = {4, 1, 2};
      vector<int> nums2 = {1, 3, 4, 2};

      vector<int> ans = nextGreaterElement(nums1, nums2);
      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}