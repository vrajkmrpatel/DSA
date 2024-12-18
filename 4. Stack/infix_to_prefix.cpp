#include <bits/stdc++.h>

using namespace std;

int precedence(char op)
{
      if (op == '^')
            return 3;
      else if (op == '*' || op == '/')
            return 2;
      else if (op == '+' || op == '-')
            return 1;
      return 0;
}

string infixToPostfix(string &s)
{
      int n = s.length();

      // initialize the empty stack
      stack<char> st;
      string postfix = "";

      for (auto c : s)
      {
            if (isalnum(c))
            {
                  postfix += c;
            }
            else if (c == '(')
            {
                  st.push(c);
            }
            else if (c == ')')
            {
                  while (!st.empty() && st.top() != '(')
                  {
                        postfix += st.top();
                        st.pop();
                  }
                  if (!st.empty())
                        st.pop();
            }
            else
            {
                  // if precedence of curr_char is less than top of the stack then pop out
                  // top and add it to postfix
                  // push the curr_char onto stack
                  while (!st.empty() && precedence(c) < precedence(st.top()))
                  {
                        postfix += st.top();
                        st.pop();
                  }
                  st.push(c);
            }
      }

      // pop out all the remaining operator from the stack
      while (!st.empty())
      {
            postfix += st.top();
            st.pop();
      }
      return postfix;
}
string infixToPrefix(string &infix)
{
      // 1) Reverse the given infix expression
      reverse(infix.begin(), infix.end());

      // convert '(' to ')' and ')' to '('
      for (char &c : infix)
      {
            if (c == '(')
                  c = ')';
            else if (c == ')')
                  c = '(';
      }

      // 2) convert it to postfix
      string postfix = infixToPostfix(infix);

      // 3) reverse again to get prefix notation
      reverse(postfix.begin(), postfix.end());

      return postfix;
}
int main()
{
      string infix = "(a+b)*c-d+f";

      string prefix = infixToPrefix(infix);
      cout << prefix << endl;
      return 0;
}