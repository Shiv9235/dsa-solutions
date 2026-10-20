#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    string s = "tree";
    string ans;

    int hash[256] = {0};
    int largest = 1;

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }

    while ( largest != 0)
    {
        largest = max_element(hash, hash + 256) - hash;

        for ( int j = 0;j < hash[largest]; j++)
        {
            ans += (char)largest;
        }
        hash[largest] = 0;
    }
    

    cout << endl << ans << endl;

    return 0;
}