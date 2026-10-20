#include <iostream>
#include <vector>

using namespace std;

bool change(vector<int> &bills)
{
    int cnt5 = 0;
    int cnt10 = 0;

    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
            cnt5++;
        else if (bills[i] == 10)
        {
            if (cnt5 == 0)
            {
                return false;
            }
            cnt5--;
            cnt10++;
        }
        else
        {
            if (cnt5 == 0)
            {
                return false;
            }
            else if (cnt10 == 0)
            {
                if (cnt5 < 3)
                {
                    return false;
                }
                else
                {
                    cnt5 = cnt5 - 3;
                    continue;
                }
            }
            cnt5--;
            cnt10--;
        }
    }

    return true;
}

int main()
{
    vector<int> bills = {5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5};

    bool ans = change(bills);

    cout << endl;
    cout << ans << endl;
    cout << endl;

    return 0;
}