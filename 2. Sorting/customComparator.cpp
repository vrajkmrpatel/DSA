#include <bits/stdc++.h>

using namespace std;

bool customComparator(int a, int b)
{
      // return true if a should appear before b
      return a > b; // for descending order
}
int main()
{
      vector<int> arr = {5, 2, 9, 1, 5, 6};

      // sort(arr.begin(), arr.end(), customComparator);
      // lambda function
      sort(arr.begin(), arr.end(), [](int a, int b)
           {
                 return a > b; // descending order})
           });

      for (int num : arr)
      {
            cout << num << " ";
      }
      return 0;
}