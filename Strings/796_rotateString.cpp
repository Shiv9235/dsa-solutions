#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s = "cdeab";
    string goal = "abcde";

    if (s.size() != goal.size())
    {
        cout << "No !!" << endl;
    }

    s = s + s;

    if (s.find(goal) != -1)
    {
        cout << "Yess !!" << endl;
    }
    else
    {
        cout << "No !!" << endl;
    }

    return 0;
}