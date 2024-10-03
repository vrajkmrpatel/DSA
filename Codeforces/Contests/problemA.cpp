#include <bits/stdc++.h>

using namespace std;

int main()
{
      int t;
      cin >> t;

      while (t--)
      {
            int n;
            cin >> n;

            string str;
            cin >> str;

            vector<int> onesIndices;

            for (int i = 0; i < str.length(); i++)
            {
                  if (str[i] == '1')
                  {
                        onesIndices.push_back(i);
                  }
            }

            int count = 0;
            int size = onesIndices.size();

            for (int i = 0; i < size; i++)
            {
                  for (int j = i + 1; j < size; j++)
                  {
                        int left = onesIndices[i];
                        int right = onesIndices[j];

                        if (right - left >= 2)
                        {
                              bool valid = true;

                              for (int k = left + 1; k < right; k++)
                              {
                                    if (str[k] == str[k - 1])
                                    {
                                          valid = false;
                                          break;
                                    }
                              }

                              if (valid)
                              {
                                    count++;
                              }
                        }
                  }
            }

            cout << count << endl;
      }
      return 0;
}