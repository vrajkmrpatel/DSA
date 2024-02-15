#include <bits/stdc++.h>

using namespace std;

int main()
{

    int num;
    cin >> num;

    int dump = num;
    int sum = 0;
    int i = (int)(log10(num) + 1);

    while (num > 0)
    {

        int lastdigit = num % 10;
        num = num / 10;
        sum = sum + (pow(lastdigit, i));
    }
    if (dump == sum)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}