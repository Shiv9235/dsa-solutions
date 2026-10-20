#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeOutMostParen(string s)
{
    string result;
    int depth = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (depth > 0)
            {
                result += s[i];
            }
            depth++;
        }
        else
        {
            depth--;
            if (depth > 0)
            {
                result += s[i];
            }
        }
    }

    return result;
}

int main()
{
    string s = "(((())(())))((()))(((())))()()(())";

    cout << endl;
    cout << removeOutMostParen(s);
    cout << endl;

    return 0;
}