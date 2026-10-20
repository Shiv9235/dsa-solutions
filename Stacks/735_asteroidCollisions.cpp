#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool sameSign(int n, int m)
{
    if ((n < 0 && m > 0) || (n > 0 && m < 0))
    {
        return false;
    }
    return true;
}

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    int n = asteroids.size();
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty() || sameSign(st.top(), asteroids[i]) || (st.top() > 0 && asteroids[i] < 0))
        {
            st.push(asteroids[i]);
        }
        else
        {
            bool destroyed = false;
            while (!st.empty() && !sameSign(st.top(), asteroids[i]))
            {
                if (-st.top() == asteroids[i])
                {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else if (-st.top() > asteroids[i])
                {
                    destroyed = true;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if (!destroyed)
            {
                st.push(asteroids[i]);
            }
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
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
    vector<int> asteroid = {3, 5, -6, 2, -1, 4};
    vector<int> ans = asteroidCollision(asteroid);

    printVector(ans);

    return 0;
}