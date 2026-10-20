#include <iostream>
using namespace std;

int main()
{
    // int nums[7] = {2,2,1,1,1,2,2};
    //  sorting
    int nums[7] = {1,1,1,2,2,2,2}; 
    int hash[1000000] = {0};
    int count = 0;

    for ( int i = 0; i < 7; i++)
    {
       hash[nums[i]]++;
    }

    for ( int i = 0; i < 7; i++)
    {
        if ( hash[nums[i]] > 7 / 2)
        {
            count = nums[i];
        }
    }
    
    cout << "Majority element : " << count;


    return 0;
}