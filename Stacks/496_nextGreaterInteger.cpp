#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int checkGreaterElement(int n, vector<int> &nums)
{
    stack<int> st;

    int i = nums.size() - 1;
    if (nums[i] == n)
    {
        return -1;
    }
    else
    {
        st.push(nums[i]);
        while (nums[i] != n)
        {
            st.push(nums[i]);
            i--;
        }
        while (!st.empty() && st.top() <= n)
        {
            st.pop();
        }
        if (st.empty())
        {
            return -1;
        }
    }

    return st.top();
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(checkGreaterElement(nums1[i], nums2));
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "    ";
    }
    cout << endl;

    return 0;
}