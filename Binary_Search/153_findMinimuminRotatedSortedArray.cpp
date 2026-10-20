#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};

    int minimum = nums[0];

    for ( int i = 1; i < nums.size(); i++)
    {
        minimum = min(minimum, nums[i]);
    }
    cout  << endl << "[" ;
    for( int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ", ";
    }
    cout  << "]" << endl;

    cout << endl << "Minimum Number in the give sorted array : " << minimum << endl << endl;

    return 0;
}