#include <bits/stdc++.h>

using namespace std;

class Stack
{
public:
      queue<int> q;

      void Push(int x)
      {
            int size = q.size();
            q.push(x);

            for (int i = 0; i < size; i++)
            {
                  q.push(q.front());
                  q.pop();
            }
      }

      int Pop()
      {

            int top = q.front();
            q.pop();
            return top;
      }

      int Top()
      {
            return q.front();
      }

      bool isEmpty()
      {
            if (q.empty())
                  return true;
            else
                  return false;
      }
};

int main()
{
      Stack *st = new Stack();

      st->Push(1);
      st->Push(2);
      cout << st->Top() << " " << st->Pop() << " " << st->Top() << " " << st->isEmpty() << endl;

      return 0;
}