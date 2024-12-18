#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

class Solution
{
public:
      int trap(vector<int> &height)
      {
            int n = height.size();
            int trappedWater = 0;

            for (int i = 0; i < n; i++)
            {
                  int leftMax = 0, rightMax = 0;
                  int j = i;
                  while (j >= 0)
                  {
                        leftMax = max(leftMax, height[j]);
                        j--;
                  }
                  j = i;
                  while (j < n)
                  {
                        rightMax = max(rightMax, height[j]);
                        j++;
                  }

                  trappedWater += min(leftMax, rightMax) - height[i];
            }
            return trappedWater;
      }
};
int main()
{
      vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

      Solution st;
      cout << st.trap(height) << endl;
}