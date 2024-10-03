#include <bits/stdc++.h>

using namespace std;

class Queue
{

      stack<int> input, output;

      void enQueue(int x)
      {
            input.push(x);
      }

      int deQueue()
      {

            if (input.empty() && output.empty())
            {
                  return -1;
            }

            if (output.empty())
            {
                  while (!input.empty())
                  {
                        output.push(input.top());
                        input.pop();
                  }
            }

            int ans = output.top();
            output.pop();
            return ans;
      }

      int peek()
      {
            if (input.empty() && output.empty())
            {
                  return -1;
            }

            if (output.empty())
            {
                  while (!input.empty())
                  {
                        output.push(input.top());
                        input.pop();
                  }
            }

            return output.top();
      }

      bool isEmpty()
      {
            return input.empty() && output.empty();
      }
}

int
main()
{

      return 0;
}