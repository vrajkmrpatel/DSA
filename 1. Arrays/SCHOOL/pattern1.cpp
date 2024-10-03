// You are given a number N. You need to print the pattern for the given value of N.

// For N = 2 the pattern will be
// 2 2 1 1
// 2 1

// For N = 3 the pattern will be
// 3 3 3 2 2 2 1 1 1
// 3 3 2 2 1 1
// 3 2 1

// Note: Instead of printing a new line print a "$" without quotes. After printing the total output, end of the line("$") is expected.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 2;
    int num = n;
    int n2 = n;
    for (int i = 0; i< n*n; i++)
    {
        // first line
        int j = n;
        while (j != 0)
        {
            cout << num << " ";
            j--;
        }
        if (num == 1)
        {
            num = n2;
        }
        else
        {
            num--;
        }
    }

    return 0;
}