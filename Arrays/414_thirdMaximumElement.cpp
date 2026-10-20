#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {1,4,2,6,8,2,4,7,8,4,6,7};

    // <----------       BRUTE SOLUTION       ---------->

    // sort(nums.begin(), nums.end());
    // nums.erase(unique(nums.begin(), nums.end()), nums.end());

    // cout << endl;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i] << endl;
    // }

    // cout << endl;

    // if ( nums.size() < 3)
    // {
    //     cout << endl << "No third maximum element. Maximum : " << *max_element(nums.begin(), nums.end()) << endl << endl;
    // }
    // else {
    //     cout << endl << "Third Maximum Element : " << nums[nums.size() - 3] << endl << endl;
    // }

    // <----------      OPTIMAL SOLUTION        ---------->

    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for (int x : nums)
    {
        // Ignoring Duplicates
        if( x == first || x == second || x == third )
        {
            continue;
        }
        else if ( x > first )
        {
            third  = second;
            second = first;
            first = x;
        }
        else if ( x > second )
        {
            third = second;
            second = x;
        }
        else if ( x > third)
        {
            third = x;
        }

    }

    // If there are fewer than 3 distinct values,
    // return the largest.
    if ( third == LLONG_MIN)
    {
        cout << endl << "No third maximum element. Maximum : " << first << endl << endl;
    }
    else
    {
        cout << endl << "Third Maximum Element : " << third << endl << endl;
    }
    return 0;
}