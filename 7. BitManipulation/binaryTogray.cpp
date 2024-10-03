#include <bits/stdc++.h>

using namespace std;

vector<int> decimalToBinary(int n)
{
      vector<int> binary;
      while (n > 0)
      {
            int num = n % 2;
            binary.push_back(num);
            n = n / 2;
      }
      reverse(binary.begin(), binary.end());

      return binary;
}
int binaryToDecimal(vector<int> binary)
{
      reverse(binary.begin(), binary.end());
      int ans = 0;
      for (int i = 0; i < binary.size(); i++)
      {
            ans = ans + (binary[i] * pow(2, i));
      }
      return ans;
}

int GrayToBinary(int n)
{
      vector<int> binary = decimalToBinary(n);
      vector<int> gray;
      gray.push_back(binary[0]);

      for (int i = 1; i < binary.size(); i++)
      {
            gray.push_back(binary[i] ^ gray[i - 1]);
      }
      return binaryToDecimal(gray);
}

int main()
{
      int n = 4;
      int ans = GrayToBinary(n);
      cout << ans;
      return 0;
}