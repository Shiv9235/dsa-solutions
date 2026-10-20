#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;

int main()
{

    string num = "6748590";

    while(!num.empty())
    {
        int lastDigit = num[num.size() - 1] - '0';

        if(lastDigit % 2 != 0)
        {
            cout << endl << "'" << num << "'" << " is largest odd number." << endl << endl;
            return 0;
        }
        else
        {
            num.pop_back();
        }    
    }

    cout << endl << "There is no Odd Number inside the string." << endl <<endl;
    return 0;
}