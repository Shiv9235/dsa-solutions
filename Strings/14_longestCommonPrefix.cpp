#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    vector<string> strs = {"flower","flow","flight"};

    if ( strs.empty()){
        cout << "The given array of string is empty !!" << endl;
    }

    //  Assume common string to be first string 

    string common = strs[0];

    //  Comparing the each character of adjacent string
    
    for ( int i = 1; i < strs.size(); i++)
    {
        int j = 0;

        //  comparing

        while
            ( j < common.size() && 
               j < strs[i].size() && 
               common[j] == strs[i][j]
            ){
                j++;
            }

            common.erase(j);
    }

    if( common.empty())
    {
        cout << "There is nothing common in the given strings." << endl;
    }

    cout << "Common substring in the string is : " << common << endl;

    return 0;
}