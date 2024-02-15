#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // iterator

    // vector<int>::iterator it1 = v.begin();
    // vector<int>::iterator it2 = v.end();

    // it1++;
    // cout << *(it1) << " ";

    // it1 = it1 + 2;
    // cout << *(it1) << " ";
    // cout << endl;

    // cout << v[0] << " " << v.at(0) << " ";

    // cout << v.back() << " ";

    // loops

    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *(it) << " ";
    // }
    // cout << endl;

    // for (auto it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *(it) << " ";
    // }
    // cout << endl;

    // for (auto it : v)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // All loops will print the same
    // 10 20 30 40 50
    // 10 20 30 40 50
    // 10 20 30 40 50

    // erase() function

    // single element deletion
    //  10 20 30 40 50
    // v.erase(v.begin() + 1); // result 10 30 40 50

    // deletion of range of values

    // 10 20 30 40 50
    // v.erase(v.begin() + 1,v.begin()+ 3); //reslult 10 40 50

    // insertion of elements in vector

    vector<int> v1(2, 100);         //{100,100}
    v1.insert(v1.begin(), 300);     //{300 100 100}
    v1.insert(v1.begin() + 1, 200); //{300 200 100 100}

    cout << v1.size()<<endl;

    for (auto it : v1)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}