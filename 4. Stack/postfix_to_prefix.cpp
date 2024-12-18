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
string postfixToPrefix(string postfix)
{
      int len = postfix.length();
      stack<string> st;

      // read postfix expression from left to right
      for (int i = 0; i < len; i++)
      {
            // if char is operand push it onto the stack
            if (isalnum(postfix[i]))
            {
                  st.push(string(1, postfix[i]));
            }

            // if is operator pop two operands and make prefix exp string
            // by concatinating operator before operand2 and operand1
            // and push it onto the stack
            else if (isOperator(postfix[i]))
            {
                  string op1 = st.top();
                  st.pop();

                  string op2 = st.top();
                  st.pop();

                  string prefix = postfix[i] + op2 + op1;
                  st.push(prefix);
            }
      }
      return st.top();
}
int main()
{
      string postfix = "ABC/-AK/L-*";

      cout << postfixToPrefix(postfix) << endl;
      return 0;
}