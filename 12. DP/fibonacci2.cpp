// Program to fibonacci number using memoization
#include <bits/stdc++.h>

using namespace std;

void printMemoTable(vector<int> &memo)
{
      for (auto it : memo)
      {
            cout << it << " ";
      }
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

      memo[n] = fibonacciUtil(n - 1, memo) + fibonacciUtil(n - 2, memo);
      // printMemoTable(memo);
      // cout << endl;
      return memo[n];
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
      vector<int> memo(n + 1, -1);

      return fibonacciUtil(n, memo);
}
int main()
{
      int n = 40;

      cout << fibonacci(n) << endl;

      return 0;
}