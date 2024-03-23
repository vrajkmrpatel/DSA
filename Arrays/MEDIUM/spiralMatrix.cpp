#include <bits/stdc++.h>

using namespace std;

vector<int> SpiralMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int left = 0, top = 0, right = m - 1, bottom = n - 1;

    vector<int> ans;

    while (left <= right && top <= bottom)
    {

        // right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix{{1, 2, 3, 4, 5},
                               {6, 7, 8, 9, 10},
                               {11, 12, 13, 14, 15},
                               {16, 17, 18, 19, 20},
                               {21, 22, 23, 24, 25}};

    vector<int> ans = SpiralMatrix(matrix);

    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    

    return 0;
}