#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int countStudents(vector<int> &arr, int pages)
{
    int students = 1;
    long long pagesStudent = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }

        else
        {
            students += 1;
            pagesStudent = arr[i];
        }
    }

    return students;
}

int bookAllocation(vector<int> &arr, int m)
{
    if (m > arr.size())
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);

        if (students > m)
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

    vector<int> arr = {12, 34, 67, 90};

    int students;

    cout << endl;
    cout << "Enter the number of students : ";
    cin >> students;

    int largest = bookAllocation(arr, students);

    cout << endl;
    cout << "Largest minimum allocation possible : " << largest << endl;
    cout << endl;

    return 0;
}