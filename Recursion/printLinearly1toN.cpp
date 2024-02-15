#include <bits/stdc++.h>

using namespace std;

void printLinearly1toN(int i, int n)
{

    if (i > n)
        return;
    cout << i << " ";
    printLinearly1toN(i + 1, n);
}

void printLinearlyNto1(int i, int n)
{
    if (i < 1)
        return;
    cout << i << " ";
    printLinearlyNto1(i - 1, n);
}

int main()
{

    int n;
    cin >> n;

    // print 1 to N
    // printLinearly1toN(1, n);

    // print N to 1 reverse order
    printLinearlyNto1(n, n);

    return 0;
}