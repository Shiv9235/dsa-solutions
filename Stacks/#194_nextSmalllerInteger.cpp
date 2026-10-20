#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextSmallerInteger(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() > arr[i])
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

        st.push(arr[i]);
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
    vector<int> arr = {10, 9, 8, 7};
    vector<int> ans = nextSmallerInteger(arr);

    printVector(arr);
    printVector(ans);

    return 0;
}