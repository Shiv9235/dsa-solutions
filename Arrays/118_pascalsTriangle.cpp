#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numRows = 5;
    vector<vector<int>> pascalTri;

    vector<int> row = {1};
    vector<int> nextRow;

    for (int i = 1; i <= numRows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j == 0)
            {
                nextRow.push_back(row[j]);
            }
            else if (j == row.size())
            {
                nextRow.push_back(row[row.size() - 1]);
            }
            else
            {
                nextRow.push_back(row[j - 1] + row[j]);
            }
        }
        pascalTri.push_back(nextRow);
        row = nextRow;
        nextRow.clear();
    }

    //      <--  ABOVE CODE AND BELOW CODE HAS THE SAME COMLEXITY IN SPACE AND TIME BUT BELOW CODE I MUCH CLEANER THAN THE BAOVE ONE  -->

    // for (int i = 0; i < numRows; i++)
    //     {
    //         vector<int> row(i + 1, 1);

    //         for (int j = 1; j < i; j++)
    //         {
    //             row[j] = pascalTri[i - 1][j - 1]
    //                    + pascalTri[i - 1][j];
    //         }

    //         pascalTri.push_back(row);
    //     }

    for (int i = 0; i < pascalTri.size(); i++)
    {
        for (int j = 0; j < pascalTri[i].size(); j++)
        {
            cout << pascalTri[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}