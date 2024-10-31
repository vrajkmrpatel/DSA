#include<bits/stdc++.h>

using namespace std;

int main()
{
      int t;
      cin >> t;

      while(t--)
      {
            int n,k;
            cin >> n >> k;

            vector<int> arr(n);
            for (int i = 0; i < n;i++)
            {
                  cin >> arr[i];
            }

            auto it = find(arr.begin(), arr.end(), k);
            if(it == arr.end())
            {
                  // element is not present
                  cout << "NO" << endl;
            }
            else{
                  cout << "YES" << endl;
            }
      }
      return 0;
}