#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        long long hour = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            hour += (piles[i] + mid - 1) / mid;
        }
        if (hour > h)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int answer = minEatingSpeed(piles, h);

    cout << endl;
    cout << answer;
    cout << endl;

    return 0;
}