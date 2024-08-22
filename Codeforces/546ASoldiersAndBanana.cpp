#include<bits/stdc++.h>

using namespace std;

int dollersToBorrow(int k, int n, int w)
{
      int dollersNeed = 0;
      int dollersHave = n;

      int i = 1;
      while(w--)
      {
            dollersNeed += k * i;
            i++;
      }

      if(dollersHave > dollersNeed)
      {
            return 0;
      }
      else {
            return dollersNeed - dollersHave;
      }
}
int main()
{
      int k, n, w;

      cin >> k >> n >> w;

      cout << dollersToBorrow(k, n, w) << endl;
      return 0;
}