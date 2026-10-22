#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string removeKDigits(string num, int k)
{
    if (k == num.size())
        return "0";

    stack<char> st;
    string ans;
    st.push(num[0]);
    for (int i = 1; i < num.size(); i++)
    {
        while (!st.empty() && k > 0 && st.top() > num[i])
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    if (k > 0)
    {
        while (k > 0)
        {
            st.pop();
            k--;
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    int i = 0;

    while (i < ans.size() && ans[i] == '0')
        i++;

    ans = ans.substr(i);

    if (ans.empty())
        return "0";

    return ans;
}

int main()
{
    return 0;
}