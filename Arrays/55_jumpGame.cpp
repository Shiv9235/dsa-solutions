#include <iostream>
#include <vector>

using namespace std;

int foundZero(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

bool jumpGame(vector<int> &maxJump)
{
    int zero = foundZero(maxJump);
    if (zero > -1)
    {
        for (int i = 0; i < zero; i++)
        {
            if (maxJump[i] + i > zero)
            {
                return true;
            }
        }
    }
    else
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int> maxJump = {2, 3, 1, 2, 0, 4};

    cout << endl;
    cout << jumpGame(maxJump) << endl;
    cout << endl;

    return 0;
}