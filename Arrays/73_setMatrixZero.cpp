#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    vector<int> row, col;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row.push_back(i);
                col.push_back(j);
            }
        }
    }

    // for (int i = 0; i < row.size(); i++)
    // {
    //     cout << row[i];
    // }

    for (int a = 0; a < row.size(); a++)
    {
        for (int b = 0; b < matrix[0].size(); b++)
        {
            matrix[row[a]][b] = 0;
        }
    }
    for (int a = 0; a < col.size(); a++)
    {
        for (int b = 0; b < matrix.size(); b++)
        {
            matrix[b][col[a]] = 0;
        }
    }

    cout << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}