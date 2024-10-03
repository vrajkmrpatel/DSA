#include <bits/stdc++.h>

using namespace std;

int main()
{

    int num;
    cin >> num;

    // // This will take O(N) time complexity
    // for (int i = 1; i <= num; i++)
    // {
    //     if (num % i == 0)
    //     {
    //         cout << i << " ";
    //     }
    // }

    // Another method to print divisor with less time complexity
    // By using sqrt(num) we can decrease the TC to O(sqrt(N))
    vector<int> ls;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            ls.push_back(i);

            if ((num / i) != i)
            {
                ls.push_back(num / i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    for (int it : ls)
    {
        cout << it << " ";
    }

    return 0;
}