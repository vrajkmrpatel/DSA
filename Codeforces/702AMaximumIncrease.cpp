#include <bits/stdc++.h>

using namespace std;

int maximumIncrease(vector<int> &arr, int n)
{
      int currentLength = 1;
      int maxLength = 1;
      for (int i = 1; i < n; i++)
      {
            if (arr[i] > arr[i - 1])
            {
                  currentLength++;
            }
            else
            {
                  maxLength = max(maxLength, currentLength);
                  currentLength = 1;
            }
      }
      maxLength = max(maxLength, currentLength);
      return maxLength;
}
int main()
{
      int n;
      cin >> n;

      vector<int> arr(n);

      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }

      cout << maximumIncrease(arr, n);

      return 0;
}