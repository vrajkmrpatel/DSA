#include <bits/stdc++.h>

using namespace std;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < (n - i - 1); j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < (n - i - 1); j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < (n - i - 1); j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < (n - i - 1); j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        // cout << i;
        if (i > n)
        {
            stars = 2 * n - i;
        }
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        int start = 1;
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}
void pattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // number
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // space
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }

        // number
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;
    }
}
void pattern12_2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i - 1; j >= 0; j--)
        {
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pattern13(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << count++ << " ";
        }
        cout << endl;
    }
}
void pattern14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char count = 'A';
        for (int j = 0; j < i; j++)
        {
            cout << count++ << " ";
        }
        cout << endl;
    }
}
void pattern15(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char count = 'A';
        for (int j = 0; j <= n - i; j++)
        {
            cout << count++ << " ";
        }
        cout << endl;
    }
}
void pattern16(int n)
{
    char count = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << count;
        }
        count++;
        cout << endl;
    }
}
void pattern17(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 0; j <= (n - i); j++)
        {
            cout << " ";
        }
        // alphabet
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j < (2 * i); j++)
        {
            cout << ch;
            if (j < breakpoint)
                ch++;
            else
                ch--;
        }
        // space
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern18(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + n - 1;

        for (int j = 1; j <= i; j++)
        {

            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }
    // for (int i = 0; i <n; i++)
    // {
    //     for (char ch = 'E' - i; ch <= 'E'; ch++)
    //     {
    //         cout << ch << " ";
    //     }
    //     cout << endl;
    // }
    // char ch = 'E';
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << ch<<" ";
    //         ch++;
    //     }
    //     ch -= i+1;
    //     cout << endl;
    // }
}
void pattern19(int n)
{
    // find symmetry first and then solve the questions.

    // uperhalf
    int inispace = 0;
    for (int i = 0; i < n; i++)
    {
        // star
        for (int j = 1; j <= (n - i); j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < inispace; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 1; j <= (n - i); j++)
        {
            cout << "*";
        }
        inispace += 2;
        cout << endl;
    }

    // remaining portion
    inispace = 8;
    for (int i = 1; i <= n; i++)
    {
        // star
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < inispace; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        inispace -= 2;
        cout << endl;
    }
}
void pattern20(int n)
{
    int inispace;
    inispace = 8;
    for (int i = 1; i <= n; i++)
    {
        // star
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < inispace; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        inispace -= 2;
        cout << endl;
    }

    inispace = 2;
    for (int i = 0; i < n - 1; i++)
    {
        // star
        for (int j = 1; j <= (n - i - 1); j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < inispace; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 1; j <= (n - i - 1); j++)
        {
            cout << "*";
        }
        inispace += 2;
        cout << endl;
    }
}
void pattern21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                cout << "*"
                     << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
void pattern22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2 * n - 1) - 1 - j;
            int bottom = (2 * n - 1) - 1 - i;

            cout << (n - min(min(top, bottom), min(left, right)));
        }
        cout << endl;
    }
}
int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        pattern20(n);
    }
    return 0;
}