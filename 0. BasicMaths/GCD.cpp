#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{

    // Find min of two numbers and find out highest divisor of that min which divides both
    // O(min(a,b))
    // int res = min(a, b);
    // while (res > 0)
    // {
    //     if (a % res == 0 && b % res == 0)
    //     {
    //         break;
    //     }
    //     res--;
    // }
    // cout << res << endl;

    // Using Euclidean Algorithm
    // if (a == 0)
    //     return b;
    // if (b == 0)
    //     return a;

    // if (a == b)
    //     return a;

    // if (a > b)
    //     return GCD(a - b, b);
    // return GCD(a, b - a);

    // Using Modulo iterative operation
    // while (a > 0 && b > 0)
    // {
    //     if (a > b)
    //         a = a % b;
    //     else
    //     {
    //         b = b % a;
    //     }
    // }
    // if (a == 0)
    //     return b;
    // else
    //     return a;

    return __gcd(a, b);
}

int main()
{

    int a, b;
    cin >> a >> b;

    cout << GCD(a, b) << endl;
    return 0;
}