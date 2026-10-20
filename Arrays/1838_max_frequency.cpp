#include <iostream>
using namespace std;

int main()
{
    int nums[3] = {1,2,4};
    int k = 5;
    int sum = 0;
    int l = 0;
    int ans = 0;

    for ( int r = 0; r < 3; r ++)
    {
        sum += nums[r];

        while ( nums[r] * (r - l + 1) - sum > k )
        {
            sum -= nums[l];
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    cout << "Maximum Frequency : " << ans << endl;

    return 0;
}