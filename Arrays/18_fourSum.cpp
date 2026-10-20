#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        int left = i + 1;
        int right = j - 1;
        int sum = nums[i] + nums[j] + nums[left] + nums[right];

        while (left < right)
        {

            if (sum == target)
            {
                ans.push_back({nums[i], nums[j], nums[left], nums[right]});
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        if (sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return ans;
}

int main()
{
}