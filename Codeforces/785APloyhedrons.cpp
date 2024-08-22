#include <bits/stdc++.h>

using namespace std;

int main()
{
      int n;
      cin >> n;

      int faces = 0;

      while (n--)
      {
            string str;
            cin >> str;

            if (str == "Tetrahedron")
            {
                  faces += 4;
            }
            else if (str == "Cube")
            {
                  faces += 6;
            }
            else if (str == "Octahedron")
            {
                  faces += 8;
            }
            else if (str == "Dodecahedron")
            {
                  faces += 12;
            }
            else if (str == "Icosahedron")
            {
                  faces += 20;
            }
      }

      cout << faces << endl;
      return 0;
}