#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int countK(vector<int> &arr, int barrier)
{
    int k = 1;
    long long sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] <= barrier)
        {
            sum += arr[i];
        }

        else
        {
            k += 1;
            sum = arr[i];
        }
    }

    return k;
}

int splitArray(vector<int> &nums, int k)
{
    if (k > nums.size())
    {
        return -1;
    }

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int painters = countK(nums, mid);

        if (painters > k)
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

    int largest = splitArray(nums, painters);

    cout << endl;
    cout << "Largest minimum allocation possible : " << largest << endl;
    cout << endl;

    return 0;
}