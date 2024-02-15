#include <bits/stdc++.h>

using namespace std;

void printNtimes(string str, int n)
{
    if (n == 0)
        return;
    cout << str <<" ";
    printNtimes(str, n - 1);
}
int main()
{

    string name;
    int n;
    cin >> name >> n;

    printNtimes(name, n);

    return 0;
}