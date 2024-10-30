#include<bits/stdc++.h>

using namespace std;

int main()
{
      long long num;
      cin >> num;

      long long sum = 0;
      long long n = num;
      while(n > 0)
      {
            int rem = n % 10;
            sum += rem;
            n = n / 10;
      }

      if(sum % 9 == 0)
      {
            cout << "YES" << endl;
      }
      else {
            cout << "NO" << endl;
      }
      return 0;
}