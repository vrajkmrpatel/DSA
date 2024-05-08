#include<bits/stdc++.h>

using namespace std;

vector<string> findRelativeRanks(vector<int> &score) {
      
      unordered_map<int, int> mpp;
      vector<string> ans;

      for(int i = 0; i<score.size(); i++) {
            mpp[i] = score[i];
      } 

      sort(score.begin(), score.end());

      
}
int main()
{
      vector<int> score = {10,3,8,9,4};

      findRelativeRanks(score);

      return 0;
}