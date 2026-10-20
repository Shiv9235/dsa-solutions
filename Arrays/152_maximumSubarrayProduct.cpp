#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {2, 0, -1};

    int largest = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int product = 1;
            for (int k = i; k <= j; k++)
            {
                product = product * nums[k];
            }
            largest = max(largest, product);
        }
    }

    cout << largest << endl;

    return 0;
}