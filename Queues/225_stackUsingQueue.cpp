#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class stackImplQu
{
    queue<int> q;

    void push(int x)
    {
        int s = q.size();
        q.push(x);

        for (int i = 1; i <= s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        q.pop();
    }

    int top()
    {
        return q.front();
    }

    int size()
    {
        return q.size();
    }
};

int main()
{

    return 0;
}