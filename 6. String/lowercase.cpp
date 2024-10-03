#include<bits/stdc++.h>

using namespace std;

string toLowercase(string s)
{
      int len = s.length();

      for(int i = 0; i<len; i++)
      {
            if(s[i] > 'a' && s[i] <'z')
            {
                  continue;
            }
            else{
                  char temp = s[i] - 'A' + 'a';
                  s[i] = temp;
            }
      }
      return s;
}

int main()
{
      string st = "ABCDEFGhIJKLmnopqrstuVWXYZ";
      // cout<<st.length()<<endl;
      cout<<"Lowercase is "<<toLowercase(st)<<endl;
      return 0;
}