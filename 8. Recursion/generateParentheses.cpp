#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

vector<string> result;
// bool isValid(string &str)
// {
//       int count = 0;
//       for (char &ch : str)
//       {
//             if (ch == '(')
//             {
//                   count++;
//             }
//             else
//             {
//                   count--;
//             }
//             if (count < 0)
//                   return false;
//       }
//       return count == 0;
// }
// void solve(string &curr, int n)
// {
//       if (curr.length() == 2 * n)
//       {
//             if (isValid(curr))
//             {
//                   result.push_back(curr);
//             }
//             return;
//       }
//
//       // push open
//       curr.push_back('(');
//       solve(curr, n);
//       curr.pop_back();
//
//       // push close
//       curr.push_back(')');
//       solve(curr, n);
//       curr.pop_back();
// }

// Better Approach
void solve(string &curr, int n, int open, int close)
{
      if (curr.length() == 2 * n)
      {
            result.push_back(curr);
            return;
      }

      if (open < n)
      {
            curr.push_back('(');
            solve(curr, n, open + 1, close);
            curr.pop_back();
      }

      if (close < open)
      {
            curr.push_back(')');
            solve(curr, n, open, close + 1);
            curr.pop_back();
      }
}

vector<string> generateParenthesis(int n)
{

      // Using Recursion
      // Time: O(2^2*N * 2*N)
      // Space: O(2*N)
      string curr = "";
      int open = 0;
      int close = 0;
      solve(curr, n, open, close);
      return result;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int n = 3;

      vector<string> res = generateParenthesis(n);

      for (auto st : res)
      {
            cout << st << " ";
      }

      return 0;
}