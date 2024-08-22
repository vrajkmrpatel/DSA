#include<bits/stdc++.h>

using namespace std;

int WrongSubtraction(int n, int k)
{
      while(k--)
      {
            int rem = n % 10;

            if(rem == 0)
            {
                  n /= 10;
            }
            else{
                  n = n - 1;
            }
      }

      return n;
}
int main()
{
      int n,k;
      cin >> n>>k;

      cout << WrongSubtraction(n,k) << endl;
      return 0;
}