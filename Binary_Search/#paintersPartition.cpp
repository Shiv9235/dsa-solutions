#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int countPainter(vector<int> &arr, int board)
{
    int painters = 1;
    long long work = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (work + arr[i] <= board)
        {
            work += arr[i];
        }

        else
        {
            painters += 1;
            work = arr[i];
        }
    }

    return painters;
}

int paintersPartition(vector<int> &nums, int m)
{
    if (m > nums.size())
    {
        return -1;
    }

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int painters = countPainter(nums, mid);

        if (painters > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{

    vector<int> nums = {12, 34, 67, 90};

    int painters;

    cout << endl;
    cout << "Enter the number of painters : ";
    cin >> painters;

    int largest = paintersPartition(nums, painters);

    cout << endl;
    cout << "Largest minimum allocation possible : " << largest << endl;
    cout << endl;

    return 0;
}