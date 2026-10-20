#include <iostream>
#include <string>
#include <stack>

using namespace std;

int maxDepth(string s)
{
    int depth = 0;
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            cnt++;
            depth = max(cnt, depth);
        }
        else if (s[i] == ')')
        {
            cnt--;
        }
        else
        {
            continue;
        }
    }

    return depth;
}

int main()
{
    string s = "()(())((()()))";
    int ans = maxDepth(s);

    cout << endl;
    cout << ans;
    cout << endl;

    return 0;
}
