#include <bits/stdc++.h>

using namespace std;

string decimalToBinary(int n)
{
      string res = "";
      while (n > 0)
      {
            if (n % 2 == 1)
            {
                  res += '1';
            }
            else
            {
                  res += '0';
            }
            n = n / 2;
      }
      reverse(res.begin(), res.end());
      return res;
}

int BinaryTodecimal(string binary)
{
      int len = binary.length(); 
      int p2 = 1;
      int num = 0;
      for(int i = len - 1; i>= 0; i--)
      {
            if(binary[i] == '1')
            {
                  num = num + p2;
            }
            p2 = p2 * 2;
      }
      return num;
}

int main()
{

      int n = 13;
      string ans = decimalToBinary(n);
      for (auto s : ans)
      {
            cout << s;
      }
      cout<<endl;
      int integer = BinaryTodecimal(ans);
      cout << integer;
      return 0;
}