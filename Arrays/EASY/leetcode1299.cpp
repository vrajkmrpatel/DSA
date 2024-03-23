#include <bits/stdc++.h>

using namespace std;

vector<int> ReplaceWithGreatestOnRight(vector<int> &arr)
{
    // BRUTE
    // TIME COMPLEXITY - O(N^2)
    // int n = arr.size();
    // int count = 0;
    // int maxTillNow = INT_MIN;

    // if (n == 1)
    // {
    //     arr[n - 1] = -1;
    //     return arr;
    // }

    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         maxTillNow = max(maxTillNow, arr[j]);
    //     }
    //     arr[i] = maxTillNow;
    //     maxTillNow = 0;
    // }
    // arr[n - 1] = -1;

    // cout << "Arr size is not zero" << endl;
    // return arr;

    // OPTIMAL
    // SOLUTION IN ONE LOOP

    int n = arr.size();
    vector<int> v(n);
    v[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        v[i] = max(v[i + 1], arr[i + 1]);
    }

    return v;
}
int main(){
    vector<int> arr{400};

vector<int> v = ReplaceWithGreatestOnRight(arr);

for (auto it : v)
{
    cout << it << " ";
}
return 0;
}