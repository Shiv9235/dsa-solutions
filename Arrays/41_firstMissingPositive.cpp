#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int k = 1;

    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] < k)
        {
            continue;
        }
        if (nums[i] == k)
        {
            k++;
        }
        else if (nums[i] > k)
        {
            break;
        }
        i++;
    }

    return k;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 7, 8, 9, 11, 12};

    int ans = firstMissingPositive(nums);

    cout << endl;
    cout << ans;
    cout << endl;

    return 0;
}