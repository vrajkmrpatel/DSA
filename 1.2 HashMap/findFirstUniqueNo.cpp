#include <bits/stdc++.h>

using namespace std;

int findFirstUniqueNo(vector<int> &arr)
{
      int n = arr.size();

      // using map
      unordered_map<int, int> mpp;

      for (auto current : arr)
      {
            if (mpp.find(current) != mpp.end())
            {
                  mpp[current] += 1;
            }
            else
            {
                  mpp[current] = 1;
            }
      }

      for (auto current : arr)
      {
            if (mpp[current] == 1)
            {
                  return current;
            }
      }

      return -1;
}
int main()
{
      vector<int> arr = {4, 5, 1, 2, 0, 4, 5, 2};

      int ans = findFirstUniqueNo(arr);

      cout << ans << endl;
      return 0;
}