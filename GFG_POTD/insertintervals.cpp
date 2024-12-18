#include <bits/stdc++.h>

using namespace std;

void insertIntervals(vector<vector<int>> &intervals, vector<int> &newIntervals)
{
      int n = intervals.size();
      vector<vector<int>> ans;

      // add newInterval to intervals
      intervals.push_back({newIntervals[0], newIntervals[1]});

      // sort them
      sort(intervals.begin(), intervals.end());

      // merging overlapping intervals
      int st = intervals[0][0], end = intervals[0][1];
      for (int i = 1; i < n; i++)
      {
            if ((end >= intervals[i][0] && end <= intervals[i][1]) || (end > intervals[i][1]))
            {
                  st = min(st, intervals[i][0]);
                  end = max(end, intervals[i][1]);
            }
            else
            {
                  ans.push_back({st, end});
                  st = intervals[i][0];
                  end = intervals[i][1];
            }
      }
      ans.push_back({st, end});

      // return
      for (auto it : intervals)
      {
            cout << it[0] << " " << it[1] << endl;
      }
}
int main()
{
      vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
      vector<int> newIntervals = {5, 9};

      insertIntervals(intervals, newIntervals);
      return 0;
}