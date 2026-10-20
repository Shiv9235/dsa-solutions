#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> ans(nums.size());

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(nums[i % n]);
    }

    return ans;
}

void printVector(vector<int> &nums)
{
    cout << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "      ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {2, 10, 12, 1, 11};
    vector<int> ans = nextGreaterElement(nums);

    printVector(nums);
    printVector(ans);

    return 0;
}