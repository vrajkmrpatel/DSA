#include <bits/stdc++.h>

using namespace std;
int bestTimeToBuyAndSellStock(vector<int> &prices)
{
    int n = prices.size();
    int mini = prices[0];
    int maxProfit = 0;
    int cost;
    for (int i = 1; i < n; i++)
    {
        cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}
int main()
{
    vector<int> arr = {7, 1, 5, 4, 3, 6};

    int ans = bestTimeToBuyAndSellStock(arr);

    cout << ans;
    return 0;
}