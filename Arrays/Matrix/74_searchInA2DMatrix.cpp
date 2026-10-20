#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // int rows = matrix.size();
    // int cols = matrix[0].size() - 1;

    // int i = 0;
    // int j = cols;

    // while (i < rows && j >= 0)
    // {
    //     if (matrix[i][j] == target)
    //     {
    //         return true;
    //     }
    //     else if (matrix[i][j] > target)
    //     {
    //         j--;
    //     }
    //     else
    //     {
    //         i++;
    //     }
    // }
    // return false;

    //      <------------           OPTIMAL SOLUTION            -------------->

    if (matrix.size() == 0)
    {
        return false;
    }

    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (matrix[mid / m][mid % m] == target)
        {
            return true;
        }
        else if (matrix[mid / m][mid % m] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target;
    cout << endl;
    cout << "Enter number to search : ";
    cin >> target;

    bool isPresent = searchMatrix(matrix, target);

    cout << endl;
    cout << target << " is present : " << isPresent << endl;
    cout << endl;

    return 0;
}