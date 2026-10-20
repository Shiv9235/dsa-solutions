#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int largest = INT_MIN;
    int sum = 0;
    int ansStart;
    int ansEnd;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum > largest)
        {
            largest = sum;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
            ansStart = i + 1;
        }
    }

    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}