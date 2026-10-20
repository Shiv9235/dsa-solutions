#include <iostream>
#include <vector>

using namespace std;

int findSmallestDivisor(vector<int> &nums, int threshold)
{
    int high = *max_element(nums.begin(), nums.end());
    int low = 1;

    if (nums.size() == threshold)
    {
        return high;
    }

    while (low < high)
    {
        long long ans = 0;
        int mid = (low + high) / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans + (nums[i] + mid - 1) / mid;
        }
        if (ans > threshold)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int ans = findSmallestDivisor(nums, threshold);

    cout << endl;
    cout << ans;
    cout << endl;
    return 0;
}