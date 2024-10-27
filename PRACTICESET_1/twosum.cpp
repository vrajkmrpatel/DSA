#include <bits/stdc++.h>

using namespace std;

bool checkSum(vector<int> &arr, int target)
{
      // OPTIMAL TWO POINTER
      // TIME - O(N + N*LOGN)
      // SPACE - O(1)

      int n = arr.size();
      sort(arr.begin(), arr.end()); // O(nlogn)

      int left = 0;
      int right = n - 1;
      while (left < right)
      {
            int sum = arr[left] + arr[right];
            if (sum == target)
            {
                  return true;
            }
            else if (sum < target)
                  left++; 
            else
                  right--;
      }
      // if no pair is found
      return false;
}
int main()
{
      vector<int> arr = {1, 5, 5, 5, 5, 7};

      if (checkSum(arr, 10))
            cout << "true" << endl;
      else
            cout << "false" << endl;

      return 0;
}