#include <bits/stdc++.h>

using namespace std;

int main()
{

      vector<int> v = {18, 11, 8, 5, 34};

      // priority-queue
      priority_queue<int> pq;

      for (auto it : v)
      {
            pq.push(it);
      }

      while (!pq.empty())
      {
            cout << pq.top() << ' ';
            pq.pop();
      }

      cout << endl;

      // min-heap using priority-queue

      priority_queue<int, vector<int>, greater<int>> mh;

      for (auto it : v)
      {
            mh.push(it);
      }

      while (!mh.empty())
      {
            cout << mh.top() << " ";
            mh.pop();
      }

      return 0;
}