#include <iostream>
using namespace std;

int main()
{
    int nums[3] = {2,0,1};
    int temp = 0;

    for ( int i = 0; i < 2; i ++)
    {
        for (int j = 0; j < 2 - i; j ++)
        {
            if ( nums[j+1] < nums[j])
            {
                temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }

    

    for( int i = 0; i < 3; i++)
    {
        cout << nums[i] << endl; 
    }

    return 0;
}