#include <iostream>
using namespace std;

int main()
{
    int n = 37, t = 6;
    int a, b, c = 1;
    int product;
        while ( c != 0)            
        {
            a = n % 10;
            b = n / 10;
            
            if ( n == 100)
            {
                product = 0;
            }   else {
               product = a * b;
            }
            if ( product % t != 0)
            {
              n++;
            }
            else {
               c = 0;
           }
        }
    cout << n;


    return 0;
}