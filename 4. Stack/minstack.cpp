#include <bits/stdc++.h>

using namespace std;

class MinStack
{
private:
      int minEle = INT_MAX;
      stack<int> st;

public:
      /*returns min element from stack*/
      int getMin()
      {

            // Write your code here
            return st.empty() ? -1 : minEle;
      }

      int top()
      {
            if (st.empty())
            {
                  return -1;
            }

            int x = st.top();

            if (minEle < x)
            {
                  return x;
            }
            return minEle;
      }
      /*returns poped element from stack*/
      int pop()
      {

            // Write your code here
            if (st.empty())
            {
                  return -1;
            }

            int x = st.top();
            st.pop();

            if (x < minEle)
            {
                  int premin = minEle;
                  minEle = 2 * minEle - x;
                  return premin;
            }
            else
            {
                  return x;
            }
      }

      /*push element x into the stack*/
      void push(int x)
      {

            // Write your code here

            if (st.empty())
            {
                  minEle = x;
                  st.push(minEle);
            }
            else
            {
                  if (x >= minEle)
                  {
                        st.push(x);
                  }
                  else
                  {
                        st.push(2 * x - minEle);
                        minEle = x;
                  }
            }
      }
};

int main()
{
      MinStack s;

      s.push(3);
      s.push(5);
      s.getMin();
      s.push(2);
      s.push(1);
      s.getMin();
      s.pop();
      s.getMin();
      s.pop();
      s.top();

      return 0;
}