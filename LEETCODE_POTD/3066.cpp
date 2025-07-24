#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int minOperations(vector<int> &nums, int k)
{

      // creating min-heap
      priority_queue<long, vector<long>, greater<long>> pq;
      int noOfOp = 0;
      for (int num : nums)
      {
            pq.push(num);
      }

      if (pq.top() >= k)
            return 0;
      while (pq.size() >= 2 && pq.top() < k)
      {
            long first = pq.top();
            pq.pop();
            long second = pq.top();
            pq.pop();

            pq.push(2 * first + second);
            noOfOp++;
      }
      return noOfOp;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> nums = {2, 11, 10, 1, 3};
      cout << minOperations(nums, 10) << endl;

      return 0;
}