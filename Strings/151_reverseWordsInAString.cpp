#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s = "   the    sky is blue";;

    vector<string> words;
    string s1;

    int i = 0;
    while(i < s.size())
    {    
        while(s[i] != ' ' && i < s.size())
        {
            s1.push_back(s[i]); 
            i++; 
        }
        if (!s1.empty())
        {
            words.push_back(s1);
        }
        s1.clear();
        i++;
    }

    s.clear();

    for ( int i = (int)words.size() - 1; i >= 0; i--)
    {
        s += words[i];
        if( i > 0)
        {
            s.push_back(' ');
        }
    }

    cout << endl << "'"<< s << "'"<< endl << endl;

    return 0;

}