#include <bits/stdc++.h>

using namespace std;

void reverseArray(vector<int> &arr)
{
    int p = 0;
    int q = arr.size() - 1;

    while (p < q)
    {
        swap(arr[p++], arr[q--]);
    }
}
void rotateMatrix90(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    // Transpose of Matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // reverse each row
    // for (int i = 0; i < n; i++)
    // {
    //     reverse(mat[i].begin(), mat[i].end());
    // }

    for (int i = 0; i < n; i++)
    {
        reverseArray(mat[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> mat{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};

    rotateMatrix90(mat);
    return 0;
}