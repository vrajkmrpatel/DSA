#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N = 3;
    vector<vector<int>> arr{{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

    int rp = 0;
    int cp = 0;

    for (int i = 0; i < N; i++)
    {
        swap(arr[rp][cp], arr[cp][rp]);
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << arr[j][i] << " ";
    //     }
    // }

    return 0;
}