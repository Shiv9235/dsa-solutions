#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {1,2,3};
    int i, j;

    // If array starts as an increasing array
    if ( nums[0] < nums[1])
    {
        for (i = 0; i < nums.size() - 1; i++)
        {
            if ( nums[i] > nums[i+1])
            {
                break;
            }
        }
        // cheking peak ofr an increasing array
        if ( i == nums.size() - 1)
        {
            cout << endl << "There is no peak in this given array." << endl << endl;
        }
        else
        {
            if ( nums[i -1] < nums[i] && nums[i] > nums[i+1])
            {
                cout << endl << "The peak is at the index : " << i << endl << endl;
            }

        }
    }

    // if array statrts as decreasing array

    else if ( nums[0] > nums[1]){

        // Finding minima of the array

        for(i = 0; i < nums.size() - 1; i++)
        {
            if ( nums[i] < nums[i+1])
            {
                break;
            }
        }

        // Finding Maxima of the array

        for (j = i; j < nums.size() - 1; j++)
        {
            if ( nums[j] > nums[j+1])
            {
                break;
            }
        }
        // checking if maxima if last element of the function
        if ( j == nums.size() - 1)
        {
            cout << endl << "There is no peak in this given array." << endl << endl;
        }

        // checking if it is not a stable point or a peak
        else
        {
            if ( nums[j -1] < nums[j] && nums[j] > nums[j+1])
            {
                cout << endl << "The peak is at the index : " << j << endl << endl;
            }

        }

    }
    

    return 0;
}