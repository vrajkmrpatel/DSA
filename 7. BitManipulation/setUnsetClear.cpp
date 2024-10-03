#include <bits/stdc++.h>

using namespace std;

bool checkithBit(int n, int i)
{
      if (n & (1 << i))
      {
            return true;
      }
      else
      {
            return false;
      }
}
int setithBit(int n, int i)
{
      return n | (1 << i);
}

int clearithBit(int n, int i)
{
      return n & ~(1 << i);
}
int main()
{
      int n = 9;
      int i = 2;

      cout << checkithBit(n, i) << endl;
      cout << setithBit(n, i) << endl;
      cout << clearithBit(n, i) << endl;
      return 0;
}