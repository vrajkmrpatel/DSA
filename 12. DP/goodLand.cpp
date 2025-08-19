#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalSquareBruteForce(vector<vector<int>> &mat)
{
    int rows = mat.size();
    if (rows == 0)
        return 0;
    int cols = mat[0].size();
    int maxSide = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (mat[i][j] == 1)
            {
                int side = 1;
                bool squarePossible = true;

                while (i + side < rows && j + side < cols && squarePossible)
                {
                    // Check new row
                    for (int k = j; k <= j + side; ++k)
                    {
                        if (mat[i + side][k] == 0)
                        {
                            squarePossible = false;
                            break;
                        }
                    }
                    // Check new column
                    for (int k = i; k <= i + side; ++k)
                    {
                        if (mat[k][j + side] == 0)
                        {
                            squarePossible = false;
                            break;
                        }
                    }
                    if (squarePossible)
                    {
                        ++side;
                    }
                }
                maxSide = max(maxSide, side);
            }
        }
    }

    return maxSide * maxSide; // return area
}

int main()
{
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}};

    cout << "Maximum square area of good land: " << maximalSquareBruteForce(mat) << endl;

    return 0;
}
