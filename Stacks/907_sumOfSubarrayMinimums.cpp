#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
#include <list>

using namespace std;

vector<int> nextSmallerInteger(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = n;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(i);
    }

    return ans;
}

vector<int> previousSmallerInteger(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
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

        st.push(i);
    }

    return ans;
}

int sumSubarrayMins(vector<int> &arr)
{
    vector<int> nse = nextSmallerInteger(arr);
    vector<int> pse = previousSmallerInteger(arr);
    int total = 0;
    long long mod = (int)(1e9 + 7);

    for (int i = 0; i < arr.size(); i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
    }

    return total;
}

int main()
{
    vector<int> arr = {11, 81, 94, 43, 3};

    int ans = sumSubarrayMins(arr);

    cout << endl;
    cout << ans << endl;
    cout << endl;

    return 0;
}