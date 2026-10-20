#include <iostream>
#include <map> 
using namespace std;

int main()
{


    int arr[5] = {3,5,2,7,9};
    int target = 12;

    // <-------------------      BRUTE SOLUTION       ---------------------->

    // int result[2] = {0};

    // for ( int i = 0; i < 5; i ++)
    // {
    //     for ( int j = i+1; j < 5; j++)
    //     {
    //         if ( arr[i] + arr[j] == target)
    //         {
    //             result[0] = i;
    //             result[1] = j;
    //         }
    //     }
    // }

    // cout << "The taget given is achieved by the sum of element agt the indices " << result[0] << " and " << result[1] << ".";

    // <--------------------      BETTER SOLUTION       -------------------------->

    // in this we are going to use hashing

    // map <int,int> mpp;
    // for( int i = 0; i < 5; i ++)
    // {
    //     int num = arr[i];
    //     int moreNeeded = target - num;
    //     if( mpp.find(moreNeeded) != mpp.end())
    //     {
    //         return {mpp[moreNeeded], i};
    //     }
    //     mpp[num] = i;
    // }

    // <-------------------     OPTIMAL SOLUTION      ------------------------->

    return 0;
}