#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {1,1,2,2,3,3,4,4,8,8};
    int hash[100000] = {0};

        for(int i = 0; i < nums.size(); i ++)
        {
            hash[nums[i]]++;
        }

        cout << endl << "[" ;
        for( int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << ", ";
        }
        cout  << "]" << endl << endl;

        for(int i = 0; i < nums.size(); i++)
        {
            if( hash[nums[i]] == 1)
            {
                cout << "Single element in the given array : " << nums[i] << endl << endl;
                return 0;
            }
        }

        cout << "There is no single element in this array" << endl << endl;

        return 0;
}