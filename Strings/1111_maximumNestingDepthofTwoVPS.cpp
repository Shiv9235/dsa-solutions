#include <iostream>
#include <vector>

using namespace std;

vector<int> maxDepthAfterSplit(string s)
{
    vector<int> ans;
    int depth = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            depth++;
            ans.push_back(depth % 2);
        }
        else
        {
            ans.push_back(depth % 2);
            depth--;
        }
    }

    return ans;
}

void printVector(vector<int> a)
{
    cout << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "    ";
    }
    cout << endl;
}

int main()
{
    vector<int> ans;
    string s = "((()))(()(()()))";

    ans = maxDepthAfterSplit(s);

    printVector(ans);

    return 0;
}