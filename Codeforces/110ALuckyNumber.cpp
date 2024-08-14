#include <bits/stdc++.h>

using namespace std;

bool isLucky(int num)
{
      string str = to_string(num);

      for (char digi : str)
      {
            if (digi != '4' && digi != '7')
            {
                  return false;
            }
      }
      return true;
}

string findLuckyNumber(long long n)
{
      int luckyDigitCount = 0;
      string nstr = to_string(n);

      for (char digit : nstr)
      {
            if (digit == '4' || digit == '7')
            {
                  luckyDigitCount++;
            }
      }

      if (isLucky(luckyDigitCount))
      {
            return "YES";
      }
      else
      {
            return "NO";
      }
}

int main()
{
      long long n;
      cin >> n;

      cout << findLuckyNumber(n) << endl;
      return 0;
}