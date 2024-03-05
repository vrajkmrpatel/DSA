#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    // cout << "Enter the decimal Number:";
    cin >> n;

    int a[10];
    for (int i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }

    for (int i = i - 1; i >= 0; i--)
    {
        cout << a[i];
    }
    return 0;
}