#include <bits/stdc++.h>

using namespace std;

int findSquareRoot(int n)
{
      // Linear Search
      // O(N)

      // int ans = 1;

      // for (int i = 1; i <= n; i++)
      // {

      //       if ((i * i) <= n)
      //       {
      //             ans = i;
      //       }
      //       else
      //       {
      //             break;
      //       }
      // }
      // return ans;

      // Binary Search
      // O(LogN)

      int low = 1;
      int high = n;

      while (low <= high)
      {

            long long mid = low + (high - low)/2;
            long long val = mid * mid;

            if (val <= n)
            {
                  low = mid + 1;
            }
            else
            {
                  high = mid - 1;
            }
      }
      return high;
}
int main()
{
      int num = 28;

      int root = findSquareRoot(num);
      cout << "Square Root is: " << root << endl;
      return 0;
}