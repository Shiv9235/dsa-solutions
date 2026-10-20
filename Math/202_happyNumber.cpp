#include <iostream>
using namespace std;

int main()
{
    int n = 2;
    int iterator = 1;
    while( iterator ){
        int temp = n;
        long long isHappy = 0;

        while ( n != 0)
        {
            int digit = 0;
            digit = n % 10;
            n = n / 10;
            isHappy = isHappy + (digit * digit);
        }
        if( isHappy == temp) 
        {
            cout << endl << "Entered Number is a Happy Number." << endl << endl;
            iterator = 0;
        }
        else{
            n = isHappy;
        }
    }
    // cout << endl << isHappy << endl << endl;

    return 0;
}