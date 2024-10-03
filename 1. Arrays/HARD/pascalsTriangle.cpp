#include <bits/stdc++.h>

using namespace std;

int FindNCR(int n, int r)
{
    int ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
    return ans;
}
vector<int> pascalTriangleRow(int row)
{
    // formula: row-1 C col-1
    int ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for (int i = 1; i < row; i++)
    {
        ans = ans * (row - i);
        ans /= i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int row)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= row; i++)
    {
        ans.push_back(pascalTriangleRow(i));
    }
    return ans;
}
int main()
{
    int row = 6;
    int col = 3;

    // int ans = FindNCR(row - 1, col - 1);
    // cout << ans;

    // vector<int> ans = pascalTriangleRow(row);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    vector<vector<int>> ans = pascalTriangle(row);
    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j <i+1; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}