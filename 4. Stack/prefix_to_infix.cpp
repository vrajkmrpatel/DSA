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
string prefixToInfix(string prefix)
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

            // if is opeartor pop two operands and make infix exp string 
            // by concatinating operator between two operands 
            // and push it onto the stack
            else if (isOperator(prefix[i]))
            {
                  string op1 = st.top();
                  st.pop();

                  string op2 = st.top();
                  st.pop();

                  string infix = "(" + op1 + prefix[i] + op2 + ")";
                  st.push(infix);
            }
      }
      return st.top();
}
int main()
{
      string prefix = "*-A/BC-/AKL";

      cout << prefixToInfix(prefix) << endl;
      return 0;
}