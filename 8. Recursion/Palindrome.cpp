#include <bits/stdc++.h>

using namespace std;
bool isPalindrome(int i, string str, int n)
{
    if (i >= n / 2)
    {
        return true;
    }
    if (str[i] != str[n - i - 1])
    {
        return false;
    }
    return isPalindrome(i + 1, str, n);
}
int main()
{

    string str;
    cin >> str;

    int n = str.length();

    cout << isPalindrome(0, str, n);
    return 0;
}