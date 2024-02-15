#include <iostream>

using namespace std;

int main()
{
    int asci;
    for (char i = 'A'; i < 'A' + 26; i++)
    {
        cout << i << " " << (int)(i) << endl;
    }

    return 0;
}