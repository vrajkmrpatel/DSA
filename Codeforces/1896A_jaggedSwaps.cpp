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

            vector<int> arr(n);
            for (int i = 0; i < n; i++)
                  cin >> arr[i];

            if (arr[0] != 1)
                  cout << "NO" << endl;
            else
                  cout << "YES" << endl;
      }
      return 0;
}

/*
      index i in [2, n-1]
      if(a[i-1] < a[i] > a[i+1])
            swap(a[i],a[i+1])

5
1 3 2 5 4

a1 can not be changed
      --> because index starts from 2 to n - 1
      --> so if first element is not 1 then return NO

1 3 2 5 4
  -> 1 2 3 5 4
  -> 1 2 3 4 5

*/