#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x < 2)
        return x;

    long long low = 1;
    long long high = x / 2;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;
}

int main()
{
    int x;

    cout << "Enter a number : ";
    cin >> x;

    int ans = sqrt(x);

    cout << endl;
    cout << ans << endl;
    cout << endl;

    return 0;
}