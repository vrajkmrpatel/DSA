#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

string kthCharacter(int k)
{

      string word = "a";

      while (word.size() < k)
      {
            string nextPart;
            for (int ch = 0; ch < word.size(); ch++)
            {
                  char nextChar = (word[ch] - 'a' + 1) % 26 + 'a';
                  nextPart += nextChar;
            }
            word += nextPart;
      }
      // return word[k - 1];
      return word;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      cout << kthCharacter(5) << endl;

      return 0;
}