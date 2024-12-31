#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";
int maxScore(vector<int> &cardPoints, int k)
{

      int n = cardPoints.size();
      int lsum = 0, rsum = 0, right = n - 1;
      int maxSum = 0;

      for (int i = 0; i < k; i++)
      {
            lsum = lsum + cardPoints[i];
      }
      maxSum = lsum;

      for (int i = k - 1; i >= 0; i--)
      {
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[right];
            right = right - 1;
            maxSum = max(maxSum, lsum + rsum);
      }
      return maxSum;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> cardPoints = {6, 2, 3, 4, 7, 2, 1, 7, 1};
      int k = 4;
      cout << maxScore(cardPoints, k) << endl;
      return 0;
}