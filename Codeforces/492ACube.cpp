#include <bits/stdc++.h>

using namespace std;

int main()
{
      int n;
      cin >> n;

      int height = 0;
      int totalCubes = 0;
      int currentLevel = 1;

      while (true)
      {
            int cubesForCurrentLevel = (currentLevel * (currentLevel + 1)) / 2;
            if (totalCubes + cubesForCurrentLevel <= n)
            {
                  totalCubes += cubesForCurrentLevel;
                  height++;
                  currentLevel++;
            }
            else
            {
                  break;
            }
      }

      cout << height << endl;

      return 0;
}