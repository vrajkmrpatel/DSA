#include <bits/stdc++.h>

using namespace std;

void printLinearly1toN(int i, int n)
{

    // if (i > n)
    //     return;
    // cout << i << " ";
    // printLinearly1toN(i + 1, n);

    // Using Backtracking
    // Without using f(i + 1, n)
    if(i < 1)
    {
        return;
    }
    printLinearly1toN(i - 1, n);
    cout << i << " ";
}

void printLinearlyNto1(int i, int n)
{
    // if (i < 1)
    //     return;
    // cout << i << " ";
    // printLinearlyNto1(i - 1, n);

    // Using Backtracking
    // Without using f(i - 1, n)
    if(i > n)
        return;
    printLinearlyNto1(i + 1, n);
    cout << i << " ";
}

int main()
{

    int n;
    cin >> n;

    // print 1 to N
    // printLinearly1toN(1, n);
    // printLinearly1toN(n, n);

    // print N to 1 reverse order
    // printLinearlyNto1(n, n);
    printLinearlyNto1(1, n);


    return 0;
}



// vector version 
// vector<int> printNos(int x) {
//     vector<int> v;
//     if (x == 1) {
//       return {1};
//     }

//     v = printNos(x - 1);
//     v.push_back(x);
//     return v;
// }