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
string postfixToInfix(string postfix)
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

            // if is operator pop two operands and make infix exp string
            // by concatinating operator between two operands
            // operand2 + operator + operator1
            // and push it onto the stack
            else if (isOperator(postfix[i]))
            {
                  string op1 = st.top();
                  st.pop();

                  string op2 = st.top();
                  st.pop();

                  string infix = "(" + op2 + postfix[i] + op1 + ")";
                  st.push(infix);
            }
      }
      return st.top();
}
int main()
{
      string postfix = "ABC/-AK/L-*";

      cout << postfixToInfix(postfix) << endl;
      return 0;
}