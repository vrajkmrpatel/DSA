#include <bits/stdc++.h>

using namespace std;

int getsum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int main()
{

    string s = "abcd";
    string nums = "";

    for (int i = 0; i < s.length(); i++)
    {
        int pos;

        pos = s[i] - 'a' + 1;
        nums += to_string(pos);
    }

    cout << nums;

    int k = 2;
    int sum = 0;
    for (char c : nums)
    {
        sum += c - '0'; // Sum up the digits of the resulting number
    }

    // Step 2: Apply the sum of digits transformation k times
    for (int i = 1; i < k; ++i)
    {
        sum = getsum(sum);
    }

    return sum;

    return 0;
}