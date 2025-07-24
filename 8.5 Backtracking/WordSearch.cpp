#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int m, n;
vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool find(int i, int j, vector<vector<char>> &board, int ind, string word)
{

      // base conditions
      if (ind == word.length())
            return true;
      //  out of range or already visited marked as '$'
      if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '$')
      {
            return false;
      }
      // if curr cell is not same as curr word ind
      if (board[i][j] != word[ind])
            return false;

      char temp = board[i][j];
      // marked i, j cell to be visited
      board[i][j] = '$';

      // backtracking steps
      for (auto &dir : direction)
      {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (find(new_i, new_j, board, ind + 1, word))
            {
                  return true;
            }
      }

      board[i][j] = temp;
      return false;
}
bool exist(vector<vector<char>> &board, string word)
{
      m = board.size();
      n = board[0].size();

      // loop through all the cells
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {

                  if (board[i][j] == word[0] && find(i, j, board, 0, word))
                  {

                        return true;
                  }
            }
      }
      return false;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
      string word = "SEE";

      if (exist(board, word))
      {
            cout << "EXIST" << endl;
      }
      else
      {
            cout << "NOT EXIST" << endl;
      }

      return 0;
}