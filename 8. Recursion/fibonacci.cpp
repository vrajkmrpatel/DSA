#include <bits/stdc++.h>

using namespace std;
int nthFibonacci(int n, vector<int> &memo)
{
    // if(n <= 1)
    // {
    //     return n;
    // }
    // return nthFibonacci(n - 1) + nthFibonacci(n - 2);

    if(n <= 1)
    {
        return n;
    }

    if(memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = nthFibonacci(n - 1, memo) + nthFibonacci(n - 2, memo);
    return memo[n];
}
int main()
{

    int n = 5;
    vector<int> memo(n + 1, -1);
    cout << nthFibonacci(n, memo);
    return 0;
}