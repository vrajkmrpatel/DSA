#include <bits/stdc++.h>

using namespace std;

int main()
{

      string s;
      cin >> s;

      string numbers;
      for (char c : s)
      {
            if (c != '+')
            {
                  numbers += c;
            }
      }

      // sort the string
      sort(numbers.begin(), numbers.end());

      string result;

      for (size_t i = 0; i < numbers.size(); ++i)
      {
            result += numbers[i];
            if (i < numbers.size() - 1)
            {
                  result += '+';
            }
      }
      cout << result << endl;
      return 0;
}