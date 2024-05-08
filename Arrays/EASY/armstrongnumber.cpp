#include <bits/stdc++.h>

using namespace std;

vector<string> armStrongNum(vector<int> &arr)
{
    vector<string> st;
    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        int sum = 0;
        int rem;

        while (num > 0)
        {
            rem = num % 10;
            num = num / 10;
            sum = sum + pow(rem, 3);
        }

        // cout << sum << ' ' << arr[i] << endl;
        if (sum == arr[i])
        {
            st.push_back("This is an ARMSTRONG number");
        }
        else
        {
            st.push_back("This is NOT an ARMSTRONG number");
        }
    }
    return st;
}
int main()
{

    vector<int> arr = {153, 176, 188};

    vector<string> ans = armStrongNum(arr);

    for(auto s: ans)
    {
        cout<<s<<endl;
    }
    return 0;
}