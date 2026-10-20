#include <iostream>
#include <vector>

using namespace std;

int kthMissingPositive(vector<int> &arr, int k)
{
    int i = 0;
    int j = 1;
    int cnt = 0;
    while (cnt < k)
    {
        if (i < arr.size() && arr[i] > j)
        {
            cnt++;
            j++;
        }
        else if (i < arr.size() && arr[i] == j)
        {
            i++;
            j++;
        }
        else if (i < arr.size() && arr[i] < j)
        {
            i++;
        }
        else
        {
            cnt++;
            j++;
        }
    }
    return j - 1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 5;

    cout << endl;
    cout << kthMissingPositive(arr, k);
    cout << endl;

    return 0;
}