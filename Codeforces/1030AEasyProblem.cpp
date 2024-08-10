#include <bits/stdc++.h>

using namespace std;

int main()
{
      int n;
      cin >> n;

      int arr[n];
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                  cout << "HARD" << endl;
                  break;
            }
            if (i == n - 1)
            {
                  cout << "EASY" << endl;
            }
      }

      return 0;
}