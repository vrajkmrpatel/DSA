#include <bits/stdc++.h>

using namespace std;

int main()
{

    int num;
    cin >> num;

    int dump = num;
    int reverse = 0;

    while (num > 0)
    {

        int lastdigit = num % 10;
        num = num / 10;
        reverse = reverse * 10 + lastdigit;
    }
    if (dump == reverse)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}