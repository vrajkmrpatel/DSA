#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int m, n;
int result;
int nonObstacle;
vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void backTrack(vector<vector<int>> &grid, int count, int i, int j)
{
      // base condition
      if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
      {
            return;
      }
      if (grid[i][j] == 2)
      {
            if (count == nonObstacle)
            {
                  result++;
            }
            return;
      }

      grid[i][j] = -1; // Mark visited

      // backtrack loop
      for (auto &dir : directions)
      {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            backTrack(grid, count + 1, new_i, new_j);
      }

      grid[i][j] = 0; // Unmark
}
int uniquePathsIII(vector<vector<int>> &grid)
{
      m = grid.size();
      n = grid[0].size();

      result = 0;
      nonObstacle = 0;
      int start_x = 0;
      int start_y = 0;
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  if (grid[i][j] == 0)
                        nonObstacle++;
                  if (grid[i][j] == 1)
                  {
                        nonObstacle += 1;
                        start_x = i;
                        start_y = j;
                  }
            }
      }

      int count = 0;
      backTrack(grid, count, start_x, start_y);
      return result;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
      cout << uniquePathsIII(grid) << endl;

      return 0;
}