#include <iostream>

using namespace std;

int fact( int n)
{
    if (n == 0)
     return 1;
    else // n > 0, so n-1 >= 0. Thus, fact(n-1) returns (n-1)!
     return n * fact(n - 1); // n * (n-1)! is n!
} // end fact

int sumUpTo( int n)
{
    int sum = 0;
    if (n == 1)
      sum = 1;
    else // n > 1
      sum = n + sumUpTo(n - 1);
    return sum;
} // end sumUpTo

int main()
{
   cout << "Hello World" << endl; 
   cout << "\n";
   cout << fact(3);
   cout << "\n";
   cout << sumUpTo(25);
   cout << "\n";
   return 0;
}

