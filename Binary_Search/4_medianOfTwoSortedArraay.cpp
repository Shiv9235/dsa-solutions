#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> num1 = {1,2};
    vector<int> num2 = {3,6};
    double n1, n2;

    int n = num1.size() + num2.size();

    double median;

    vector<int> arr;

    arr.insert(arr.end(), num1.begin() , num1.end());
    arr.insert(arr.end(), num2.begin() , num2.end());

    // for (int i = 0; i < n; i ++)
    // {
    //     cout << arr[i] << endl;
    // }

    sort(arr.begin(), arr.end());

    if ( n % 2 != 0)
    {
        cout << "Odd number of elements." << endl;
        median = arr[((n + 1) / 2) - 1];

    }   else 
    {
        cout << "Even number of elements." << endl;
        // median = (arr[(n/2) - 1] + arr[((n+2) / 2) - 1]) / 2;
        n1 = arr[(n/2) - 1];
        n2 = arr[((n+2) / 2)-1];
        median = (n1 + n2) / 2;
    }

    cout << median << endl;


    return 0;
}