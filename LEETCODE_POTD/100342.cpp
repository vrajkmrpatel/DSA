#include <bits/stdc++.h>

using namespace std;

double minimumAverage(vector<int> &nums)
{

      sort(nums.begin(), nums.end());
      vector<int>::iterator ip;
      ip = unique(nums.begin(), nums.end());
      nums.resize(distance(nums.begin(), ip));

      int n = nums.size();
      int i = 0;
      int j = n - 1;
      double ans = 0;

      vector<double> averages;
      while (n > 0)
      {

            int minElement = nums[i++];
            int maxElement = nums[j--];

            double avg = (double)(minElement + maxElement) / 2;

            averages.push_back(avg);

            n /= 2;
      }
      return *min_element(averages.begin(), averages.end());
      // return averages;
}
int main()
{
      vector<int> arr = {7, 8, 3, 4, 15, 13, 4, 1};

      // vector<double> ans = minimumAverage(arr);

      // for(auto it: ans) {
      //       cout << it << endl;
      // }

      double ans = minimumAverage(arr);
      cout << ans << endl;
      return 0;
}