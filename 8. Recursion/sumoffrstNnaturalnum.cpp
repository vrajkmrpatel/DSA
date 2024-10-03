// this is the program to print Sum of N natural number using loop and recursion
#include <bits/stdc++.h>

using namespace std;

// Method 1: Parameterized Resursion
void sumOfNnaturalNo(int i, int sum)
{
    if (i < 0)
    {
        cout << sum << endl;
        return;
    }
    sumOfNnaturalNo(i - 1, sum + i);
}

// Method 2: Functional Recursion
// Divide the problem in subproblem
int FunctionalMethod(int n)
{

    if (n == 0)
    {
        return 0;
    }
    return n + FunctionalMethod(n - 1);
}
int main()
{

    int n;
    cin >> n;

    // sumOfNnaturalNo(n, 0);
    int ans = FunctionalMethod(n);
    cout << ans << endl;
    return 0;
}