#include <iostream>
#include <vector>

using namespace std;

int assignCookies(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int left = 0;
    int right = 0;

    int ans = 0;

    while (left != s.size() && right != g.size())
    {
        if (s[left] < g[right])
        {
            left++;
            continue;
        }

        ans++;
        left++;
        right++;
    }

    return ans;
}

int main()
{
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};

    cout << endl;
    cout << assignCookies(g, s) << endl;
    cout << endl;

    return 0;
}