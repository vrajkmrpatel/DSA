#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s = "marvel";
    
    cout<<s.size()<<" "<<s.length()<<endl;

    reverse(s.begin(), s.end());
    cout<<s<<endl;
    return 0;
}