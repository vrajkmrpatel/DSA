#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;

    vector<int> ls;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);
            count++;

            if ((n / i) != i)
            {
                ls.push_back(n / i);
                count++;
            }
        }
    }
    if (count == 2)
    {
        cout << "Prime";
    }
    else
    {
        cout << "NOt a Prime";
    }
    return 0;
}