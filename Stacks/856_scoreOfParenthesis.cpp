#include <iostream>
#include <string>
#include <stack>

using namespace std;

int scoreOfParentheses(string s)
{
    stack<int> st;
    st.push(0);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(0);
        }
        else
        {
            int inner = st.top();
            st.pop();

            int value = 0;

            if (inner == 0)
            {
                value = 1;
            }
            else
            {
                value = 2 * inner;
            }

            st.top() += value;
        }
    }

    return st.top();
}

int main()
{
    string s = "()(())";
    int ans = scoreOfParentheses(s);

    cout << endl;
    cout << ans << endl;
    cout << endl;

    return 0;
}