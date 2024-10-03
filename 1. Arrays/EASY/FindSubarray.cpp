#include <bits/stdc++.h>

using namespace std;

void findSubarray(int arr[])
{
      int n = sizeof(arr) / sizeof(arr[0]);
      for (int i = 0; i < n; i++)
      {
            for (int j = i; j < n; j++)
            {

                  for (int k = i; k <= j; k++)
                  {
                        cout << arr[k] << " ";
                  }
                  cout << endl;
            }
      }
}
int main()
{
      int size = 4;
      int arr[size];

      for (int i = 0; i < 4; i++)
      {
            cin >> arr[i];
      }

      findSubarray(arr);

      return 0;
}