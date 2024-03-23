#include <bits/stdc++.h>

using namespace std;

// void markRowZero(vector<vector<int>> &matrix, int i, int n, int m)
// {
//     for (int j = 0; j < m; j++)
//     {
//         if (matrix[i][j] != 0)
//         {
//             matrix[i][j] = -1;
//         }
//     }
// }
// void markColZero(vector<vector<int>> &matrix, int j, int n, int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (matrix[i][j] != 0)
//         {
//             matrix[i][j] = -1;
//         }
//     }
// }
vector<vector<int>> setMatrixZero(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // // BRUTE FORCE
    // // Time - O(n * m)(n + m) + O(n*m)
    // // Approximately O(n^3)
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (matrix[i][j] == 0)
    //         {
    //             markRowZero(matrix, i, n, m);
    //             markColZero(matrix, j, n, m);
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (matrix[i][j] == -1)
    //         {
    //             matrix[i][j] = 0;
    //         }
    //     }
    // }

    // return matrix;

    // BETTER SOLUTION

    int row[n] = {0};
    int col[m] = {0};

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] == 0;
            }
        }
    }
    return matrix;
}
int main()
{
    vector<vector<int>> matrix{{1, 1, 1, 1},
                               {1, 0, 0, 1},
                               {1, 1, 0, 1},
                               {1, 1, 1, 1}};

    int n = matrix.size();
    int m = matrix[0].size();

    setMatrixZero(matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}