#include <bits/stdc++.h>

using namespace std;

bool isOperator(char x)
{
      if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%')
      {
            return true;
      }
      return false;
}
string prefixToPostfix(string prefix)
{
      int len = prefix.length();
      stack<string> st;

      // read prefix expression from right to left
      for (int i = len - 1; i >= 0; i--)
      {
            // if char is operand push it onto the stack
            if (isalnum(prefix[i]))
            {
                  st.push(string(1, prefix[i]));
            }

            // if is opeartor pop two operands and make postfix exp string
            // by concatinating operator at the end of operands 
            // and push it onto the stack
            else if (isOperator(prefix[i]))
            {
                  string op1 = st.top();
                  st.pop();

                  string op2 = st.top();
                  st.pop();

                  string postfix = op1 + op2 + prefix[i];
                  st.push(postfix);
            }
      }
      return st.top();
}
int main()
{
      string prefix = "*-A/BC-/AKL";

      cout << prefixToPostfix(prefix) << endl;
      return 0;
}