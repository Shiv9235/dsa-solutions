#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector<int> NGE(vector<int> &nums)
{
    stack<int> st;
    vector<int> ans(nums.size());

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() < nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}

void printVector(int n, vector<int> &nums)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << "      ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums;
    int n;

    cout << endl;
    cout << "Enter the number of elements : ";
    cin >> n;

    int a;
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        nums.push_back(a);
    }

    printVector(n, nums);

    vector<int> ans = NGE(nums);

    printVector(n, ans);

    return 0;
}