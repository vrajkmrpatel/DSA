#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
      stack<int> st;
      for (auto it : s)
      {
            if (it == '(' or it == '{' or it == '[')
            {
                  st.push(it);
            }
            else
            {
                  if (st.size() == 0)
                        return false;
                  char c = st.top();
                  st.pop();
                  if ((it == ')' and c == '(') or (it == '}' and c == '{') or
                      (it == ']' and c == '['))
                  {
                        continue;
                  }
                  else
                  {
                        return false;
                  }
            }
      }
      return st.empty();
}
int main()
{
      string s = "([])[";

      if (isValid(s))
      {
            cout << "VALID" << endl;
      }
      else
      {
            cout << "NOT VALID" << endl;
      }

      return 0;
}