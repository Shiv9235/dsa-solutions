#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxAlternatingSum(vector<int> &nums)
{
    long long sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
        nums[i] = abs(nums[i]);

    nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

    int j;
    for (j = 0; j < n / 2; j++)
        sum -= (nums[j] * nums[j]);
    for (; j < n; j++)
        sum += (nums[j] * nums[j]);

    return sum;
}

int main()
{
    vector<int> nums = {-3, 3, 2, -1, 1, -2};
    int n = nums.size();

    cout << endl;
    cout << maxAlternatingSum(nums);
    cout << endl;

    return 0;
}
