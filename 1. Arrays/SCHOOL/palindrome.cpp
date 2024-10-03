#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 1331;
    int rev = n;
    int num = 0;
    while (n > 0)
    {
        int rem = 0;
        rem = n % 10;
        num = num * 10 + rem;
        n = n / 10;
    }

    if (num == rev)
    {
        cout << num << " " << rev << endl;
        cout << "Palindrome";
    }
    else
    {
        cout << num << " " << rev << endl;
        cout << "not";
    }

    return 0;
}