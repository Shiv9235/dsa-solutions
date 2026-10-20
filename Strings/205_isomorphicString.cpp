#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "paper", t = "title";

    int hashS[256] = {-1}, hashT[256] = {-1};
    if(s.size() == t.size())
    {
        for(int i = 0; i < s.size(); i++)
        {
            hashS[s[i]]++;
            hashT[t[i]]++;
        }

        for ( int i = 0; i < s.size(); i++)
        {
            for (int i = 0; i < s.size(); i++)
        {
    if (hashST[s[i]] != -1 && hashST[s[i]] != t[i])
        return false;

    if (hashTS[t[i]] != -1 && hashTS[t[i]] != s[i])
        return false;

    hashST[s[i]] = t[i];
    hashTS[t[i]] = s[i];
    }            
        }

    }    



    return 0;
}
