#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    int reverse = 0;

    while (t--)
    {
        int num;
        cin >> num;

        while (num > 0)
        {

            int lastdigit = num % 10;
            num = num / 10;
            reverse = reverse * 10 + lastdigit;
        }
        cout << reverse << endl;
        reverse = 0;
    }

    return 0;
}