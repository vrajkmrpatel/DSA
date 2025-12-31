#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "A5T2C3G4A2";

    string res = "";

    for (int i = 0; i < str.size(); i += 2)
    {
        int count = (str[i + 1] - '0');

        while (count--)
        {
            res += str[i];
        }
    }

    cout << res << endl;

    return 0;
}