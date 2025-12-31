// Program to fibonacci number using memoization
#include <bits/stdc++.h>

using namespace std;

void printMemoTable(vector<int> &memo)
{
      for (auto it : memo)
      {`
            cout << it << " ";
      }
}
int fibSpaceOpti(int n)
{
      if(n <= 1)
            return n;
      int prev = 1;
      int prev2 = 0;

      for (int i = 2; i<=n; i++)
      {
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
      }
      return prev;
}
int fibTabulation(int n, vector<int>& dp)
{
      if(n <= 1)
            return n;

      dp[0] = 0;
      dp[1] = 1;

      for (int i = 2; i <= n; i++)
      {
            dp[i] = dp[i - 1] + dp[i - 2];
      }
      return dp[n];
}
int fibonacciUtil(int n, vector<int> &memo)
{

      if (n <= 1)
      {
            return n;
      }

      if (memo[n] != -1)
      {
            return memo[n];
      }

      return memo[n] = fibonacciUtil(n - 1, memo) + fibonacciUtil(n - 2, memo);
      // printMemoTable(memo);
      // cout << endl;
     
}
int fibonacci(int n)
{
      // Using recursion
      // if (n <= 1)
      // {
      //       return n;
      // }
      // return fibonacci(n - 1) + fibonacci(n - 2);

      // Using Memoization
      // vector<int> dp(n + 1, -1);

      // return fibonacciUtil(n, dp);

      // Space optimization
      return fibSpaceOpti(n);
}
int main()
{
      int n = 5;

      cout << fibonacci(n) << endl;

      return 0;
}