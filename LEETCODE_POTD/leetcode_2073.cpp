#include <bits/stdc++.h>

using namespace std;

int TimeNeededToBuyTicket(vector<int> &tickets, int k)
{
      // Naive solution
      // int n = tickets.size();
      // int count = 0;

      // while (true)
      // {
      //       for (int i = 0; i < n; i++)
      //       {
      //             if (tickets[i] == 0)
      //                   continue;
      //             tickets[i]--;
      //             count++;
      //             if (tickets[k] == 0)
      //                   return count;
      //       }
      // }

      // Linear Solution
      int n = tickets.size();
      int time = tickets[k];

      for (int i = 0; i < n; i++)
      {
            if (i < k)
            {
                  time += min(tickets[i], tickets[k]);
            }
            else if (i > k)
            {
                  time += min(tickets[i], tickets[k] - 1);
            }
      }
      return time;
}
int main()
{
      vector<int> arr = {84, 49, 5, 24, 70, 77, 87, 8};

      int count = TimeNeededToBuyTicket(arr, 3);
      cout << count << endl;

      return 0;
}