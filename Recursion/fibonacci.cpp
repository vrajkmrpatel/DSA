#include <bits/stdc++.h>

using namespace std;
vector<int> generateFibonacciNumbers(int n)
{
    vector<int> v;
    if (n == 1)
    {
        v.push_back(0);
        return v;
    }
    if (n == 2)
    {
        v = generateFibonacciNumbers(n - 1);
        v.push_back(1);
        return v;
    }
    else
    {
        v = generateFibonacciNumbers(n - 1);
        v.push_back(v[n - 2] + v[n - 3]);
    }
    return v;
}
int main()
{

    int n = 5;
    generateFibonacciNumbers(n);
    return 0;
}