#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{   
    vector<vector<int>> a = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    int n = a.size();

    cout << n << endl;

    cout << endl << "Matrix : " << endl;

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // The code has best time complexxity but it does not have the best space complexity.
    // Here spacecomplexity is O(n^2)
    
    // vector<vector<int>> rotatedImage(n, vector<int>(n));    

    // int m = 0;
    // for( int j = n - 1; j >= 0; j--)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         rotatedImage[i][j] = a[m][i];
    //     }
    //     m++;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << rotatedImage[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // This code is for the best space complexity
    // Here, Space Complexity is O(1)


    for ( int i = 0; i < n; i++)
    {
        for ( int j = i + 1; j < n; j++)
        {
            swap(a[i][j], a[j][i]);
        }

    }
    for (int i = 0; i < n; i++)
    {
        reverse(a[i].begin(), a[i].end());
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}