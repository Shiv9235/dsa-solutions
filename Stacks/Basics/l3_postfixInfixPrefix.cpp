#include <iostream>
#include <stack>

using namespace std;

string reverse(string s)
{
    string reverse = "";
    int i = s.size() - 1;

    while (i >= 0)
    {
        if (s[i] == '(')
        {
            reverse += ')';
        }
        else if (s[i] == ')')
        {
            reverse += '(';
        }
        else
        {
            reverse += s[i];
        }
        i--;
    }
    return reverse;
}

int priority(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }

    return -1;
}

string infixToPostfix(string s)
{
    int i = 0;
    string ans = "";
    stack<char> st;

    while (i < s.size())
    {
        if (
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string infixToPrefix(string s)
{
    stack<char> st;
    int i = 0;
    string ans = "";

    s = reverse(s);

    while (i < s.size())
    {
        if (
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == '^')
        {
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else
        {
            while (!st.empty() && priority(s[i]) < priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    ans = reverse(ans);

    return ans;
}

string postfixToInfix(string s)
{
    stack<string> st;
    int i = 0;

    while (i < s.size())
    {
        if (
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string convert = '(' + t2 + s[i] + t1 + ')';
            st.push(convert);
        }
        i++;
    }
    return st.top();
}

string prefixToInfix(string s)
{
    stack<string> st;
    int i = s.size() - 1;

    while (i >= 0)
    {
        if (
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string convert = '(' + t1 + s[i] + t2 + ')';
            st.push(convert);
        }
        i--;
    }

    return st.top();
}

string postfixToPrefix(string s)
{
    stack<string> st;
    int i = 0;

    while (i < s.size())

    {
        if (
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string convert = s[i] + t2 + t1;
            st.push(convert);
        }
        i++;
    }

    return st.top();
}

string prefixToPostfix(string s)
{
    stack<string> st;
    int i = s.size() - 1;

    while (i >= 0)
    {
        if (
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string convert = t1 + t2 + s[i];
            st.push(convert);
        }
        i--;
    }

    return st.top();
}

int main()
{
    string s = "*+pq-ab";
    string ans = prefixToPostfix(s);

    cout << endl;
    cout << s;
    cout << endl;
    cout << ans;
    cout << endl;
    cout << postfixToPrefix(ans);
    cout << endl;

    return 0;
}