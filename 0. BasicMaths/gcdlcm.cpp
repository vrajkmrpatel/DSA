#include <iostream>
using namespace std;

// Function to calculate GCD using Euclidean Algorithm
int gcd(int a, int b)
{
      while (b != 0)
      {
            int temp = b;
            b = a % b;
            a = temp;
      }
      return a;
}

// Function to calculate LCM
int lcm(int a, int b)
{
      return (a / gcd(a, b)) * b; // Divide first to prevent overflow
}

int main()
{
      int num1, num2;
      cout << "Enter two numbers: ";
      cin >> num1 >> num2;

      int gcdValue = gcd(num1, num2);
      int lcmValue = lcm(num1, num2);

      cout << "GCD of " << num1 << " and " << num2 << " is: " << gcdValue << endl;
      cout << "LCM of " << num1 << " and " << num2 << " is: " << lcmValue << endl;

      return 0;
}
