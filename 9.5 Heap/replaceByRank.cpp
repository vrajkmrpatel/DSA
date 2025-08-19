#include <bits/stdc++.h>

using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int N)
{

    // vector<int> sorted(arr.begin(), arr.end());

    // sort(sorted.begin(), sorted.end());

    // int rank = 1;
    // unordered_map<int, int> hash;
    // for (int i = 0; i < N; i++)
    // {
    //     if (i > 0 && sorted[i] == sorted[i - 1])
    //     {
    //         continue;
    //     }

    //     hash[sorted[i]] = rank++;
    // }

    // // traverse
    // vector<int> res(N);

    // for (int i = 0; i < N; i++)
    // {
    //     res[i] = hash[arr[i]];
    // }
    // return res;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int rank = 0;
    for (int i = 0; i < N; i++)
    {
        pq.push({arr[i], i});
    }

    vector<int> res(N);

    int lastnum = INT_MAX;

    while (!pq.empty())
    {
        int curr = pq.top().first;
        int index = pq.top().second;
        pq.pop();

        if (lastnum == INT_MAX || curr != lastnum)
        {
            rank++;
        }

        res[index] = rank;
        lastnum = curr;
    }
    return res;
}
int main()
{
    vector<int> arr = {100, 5, 70, 2};
    vector<int> res = replaceWithRank(arr, arr.size());

    for (int val : res)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}