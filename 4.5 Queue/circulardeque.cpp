#include <bits/stdc++.h>

using namespace std;

class CircularDeque
{
private:
      int *deque;
      int front, rear, capacity, size;

public:
      // Constructor
      CircularDeque(int cap)
      {
            capacity = cap;
            deque = new int[capacity];
            front = rear = -1;
            size = 0;
      }

      // Destructor
      ~CircularDeque()
      {
            delete[] deque;
      }

      bool isEmpty()
      {

            return size == 0;
      }

      bool isFull()
      {
            return size == capacity;
      }

      // insert at the Front
      void insertFront(int x)
      {
            if (isFull())
            {
                  cout << "Deque is Full" << endl;
            }

            if (isEmpty())
            {
                  front = rear = 0;
            }
            else
            {
                  front = (front - 1 + capacity) % capacity;
            }
            deque[front] = x;
            size++;
      }

      // insert at the Rear
      void insertRear(int x)
      {
            if (isFull())
            {
                  cout << "Deque is Full" << endl;
            }
            if (isEmpty())
            {
                  front = rear = 0;
            }
            else
            {
                  rear = (rear + 1) % capacity;
            }
            deque[rear] = x;
            size++;
      }

      // delete from front
      int deleteFront()
      {

            if (isEmpty())
            {
                  cout << "Deque is Empty" << endl;
            }

            int remove = deque[front];
            if (front == rear)
            {
                  front = rear = -1;
            }
            else
            {
                  front = (front + 1) % capacity;
            }
            size--;
            return remove;
      }

      // delete from rear
      int deleteRear()
      {
            if (isEmpty())
            {
                  cout << "Deque is Empty()" << endl;
            }

            int remove = deque[rear];
            if (front == rear)
            {
                  front = rear = -1;
            }
            else
            {
                  rear = (rear - 1 + capacity) % capacity;
            }
            size--;
            return remove;
      }

      int getFront()
      {
            if (isEmpty())
                  return -1;
            return deque[front];
      }

      int getRear()
      {
            if (isEmpty())
                  return -1;
            return deque[rear];
      }
};
int main()
{

      CircularDeque *cdq = new CircularDeque(5);

      cdq->insertFront(1);
      cdq->insertFront(2);
      cdq->insertFront(3);
      cdq->insertFront(4);

      return 0;
}