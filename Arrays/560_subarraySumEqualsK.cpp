#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {1, 3, 4, 6};
    int k = 4;

    int answer = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum = sum + nums[j];
            if (sum == k)
            {
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}