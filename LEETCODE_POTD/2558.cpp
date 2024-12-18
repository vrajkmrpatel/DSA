#include <bits/stdc++.h>

using namespace std;

long long pickGifts(vector<int> &gifts, int k)
{
      // Using Max Heap
      priority_queue<int> giftHeap(gifts.begin(), gifts.end());

      for (int i = 0; i < k; i++)
      {
            int max_element = giftHeap.top();
            giftHeap.pop();

            giftHeap.push(sqrt(max_element));
      }
      long long ans = 0;
      while (!giftHeap.empty())
      {
            ans += giftHeap.top();
            giftHeap.pop();
      }
      return ans;
}

int main()
{
      vector<int> gifts = {25, 64, 9, 4, 100};
      int k = 4;

      cout << pickGifts(gifts, k) << endl;
      return 0;
}