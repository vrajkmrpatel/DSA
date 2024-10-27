#include <bits/stdc++.h>

using namespace std;

int main()
{
      vector<vector<int>> arr = {{5, 9}, {1, 3}, {2, 6}, {4, 5}};

      sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b)
           {
                  // sorted by arrival time in ascending order 
                  return a[0] < b[0]; });

      for (const auto &pair : arr)
      {
            cout << "[" << pair[0] << " , " << pair[1] << "]\n";
      }
      return 0;
}