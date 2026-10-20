#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    int m = 0, n = 1;

    nums1.insert(nums1.begin(), nums2.begin(), nums2.begin() + n);
    nums1.erase(nums1.begin() + m + n, nums1.end());

    sort(nums1.begin(), nums1.end());

    cout << endl;
    for(int i = 0; i < nums1.size(); i++ )
    {
        cout << i+1 << ". " << nums1[i] << endl;
    }
    cout << endl;

    return 0;
}