#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // int largest = nums[0];
    // int currentSum = nums[0];

    // for (int i = 1; i < nums.size(); i++)
    // {
    //     // for (int j = i; j < nums.size(); j++)
    //     // {
    //     currentSum = max(nums[i], currentSum + nums[i]);
    //     largest = max(largest, currentSum);
    // }
    int largest = INT_MIN;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum > largest)
        {
            largest = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << largest << endl;

    return 0;
}