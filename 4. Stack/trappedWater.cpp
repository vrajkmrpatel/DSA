#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

class Solution
{
public:
      int trap(vector<int> &height)
      {
            // TC: O(N*N) SC:O(1)
            // Brute Force
            // int n = height.size();
            // int trappedWater = 0;
            // for (int i = 0; i < n; i++)
            // {
            //       int leftMax = 0, rightMax = 0;
            //       int j = i;
            //       while (j >= 0)
            //       {
            //             leftMax = max(leftMax, height[j]);
            //             j--;
            //       }
            //       j = i;
            //       while (j < n)
            //       {
            //             rightMax = max(rightMax, height[j]);
            //             j++;
            //       }
            //       trappedWater += min(leftMax, rightMax) - height[i];
            // }
            // return trappedWater;

            /*  // TC: O(3*N) SC: O(2*N)
            // Better Solution
            // Using prefix and suffix array
            int n = height.size();
            int waterTrapped = 0;
            int prefixMax[n], suffixMax[n];

            prefixMax[0] = height[0];
            for (int i = 1; i < n; i++)
            {
                  prefixMax[i] = max(prefixMax[i - 1], height[i]);
            }
            suffixMax[n - 1] = height[n - 1];
            for (int i = n - 2; i >= 0; i--)
            {
                  suffixMax[i] = max(suffixMax[i + 1], height[i]);
            }

            // now calculate the trapped water
            for (int i = 0; i < n; i++)
            {
                  waterTrapped += min(prefixMax[i], suffixMax[i]) - height[i];
            }
            return waterTrapped;
            */

            // Optimal Two Pointer Approach
            // TC:O(N) SC:O(1)

            int n = height.size();
            int total = 0;
            int lMax = 0, rMax = 0, l = 0, r = n - 1;

            while (l < r)
            {
                  if (height[l] <= height[r])
                  {
                        if (lMax > height[l])
                        {
                              
                              total += lMax - height[l];
                        }
                        else
                        {
                              lMax = height[l];
                        }
                        l = l + 1;
                  }
                  else
                  {
                        if (rMax > height[r])
                        {
                              total += rMax - height[r];
                        }
                        else
                        {
                              rMax = height[r];
                        }
                        r = r - 1;
                  }
            }
            return total;
      }
};
int main()
{
      vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

      Solution st;
      cout << st.trap(height) << endl;
}