#include <bits/stdc++.h>

using namespace std;

// linked list structure
class Node
{

public:
      int data;
      Node *next;

      Node(int data)
      {
            this->data = data;
            this->next = nullptr;
      }
};

// stack class 
class Stack
{

public:
      Node *top;
      int size = 0;

      Stack()
      {
            this->top = nullptr;
      }

      void Push(int x)
      {
            Node *temp = new Node(x);

            // LL is dynamic data structure
            // if memory allocation of new node fails then return false

            if (!temp)
            {
                  cout << "Stack is Overflow!" << endl;
            }

            temp->next = top;
            top = temp;
            size = size + 1;
      }

      int Pop()
      {

            if (isEmpty())
            {
                  return -1;
            }

            Node *temp = top;
            int data = temp->data;
            top = top->next;
            size = size - 1;
            delete temp;
            return data;
      }

      bool isEmpty()
      {

            if (size == 0)
            {
                  return true;
            }
            else
            {
                  return false;
            }
      }

      int Top()
      {

            if (isEmpty())
            {
                  return -1;
            }
            else
            {
                  return top->data;
            }
      }

      int Size()
      {
            return size;
      }
};

int main()
{
      Stack *st = new Stack();

      st->Push(11);
      st->Push(22);
      st->Push(33);
      st->Push(44);

      cout << st->Pop() << " " << st->Pop() << " ";

      st->Push(5);
      cout << st->Top();

      cout << " " << st->isEmpty();
      cout << " " << st->Size() << endl;

      return 0;
}