#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";
      
string smallestPalindrome(string s) {
      int n = s.size();
      vector<int> freq(26, 0);
      for (char c : s) {
            freq[c - 'a']++;
      }

      string left = "", middle = "";
      for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                  if (middle == "") {
                        middle += char(i + 'a');
                  } else {
                        return ""; 
                  }
            }
            left += string(freq[i] / 2, char(i + 'a'));
      }

      string right = left;
      reverse(right.begin(), right.end());
      return left + middle + right;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      string s;
      cin >> s;
      string result = smallestPalindrome(s);
      cout << result << "\n";

      
      return 0;
}