#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
    }

    int longest = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        if (hash.find(num - 1) == hash.end())
        {
            int count = 1;
            int next = num + 1;

            while (hash.find(next) != hash.end())
            {
                count++;
                next++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int ans = longestConsecutive(nums);

    cout << endl;
    cout << ans;
    cout << endl;

    return 0;
}