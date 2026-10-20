#include <iostream>
#include <string.h>

using namespace std;

int value(char c){
    switch (c) {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default: return 0;
    }
}

int main()
{
    string s = "MCMXCIV";
    int sum = 0;

    for ( int i = 0; i < s[i] != 0; i++)
    {
        if ( value(s[i]) < value(s[i+1]))
        {
            sum = sum - value(s[i]);
        }
        else {
            sum = sum + value(s[i]);
        }
    }

    cout << s << " : " << sum << endl;

    return 0;
}
