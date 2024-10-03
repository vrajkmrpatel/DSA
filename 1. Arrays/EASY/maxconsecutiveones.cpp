#include <bits/stdc++.h>

using namespace std;

int maxConsecutiveOnes(vector<int> &arr)
{
    int maxc = 0;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            maxc = max(maxc, cnt);
        }
        else
        {
            cnt = 0;
        }
    }
    return maxc;
}
int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1, 1, 0, 1, 1};

    int ans = maxConsecutiveOnes(arr);
    cout << ans;
    return 0;
}