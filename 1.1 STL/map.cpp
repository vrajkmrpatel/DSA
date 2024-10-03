#include <bits/stdc++.h>

using namespace std;

void print(map<int, string> &m)
{

    cout << m.size() << endl;
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main()
{
    // Map

    map<int, string> m;
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    m[5] = "cde";

    print(m);

    auto it = m.find(3);
    // if (it == m.end())
    // {
    //     cout << "No Value" << endl;
    // }
    // else
    // {
    //     cout << it->first << " " << it->second << endl;
    // }
    return 0;
}