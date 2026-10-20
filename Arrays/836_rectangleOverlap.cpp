#include <iostream>
#include <vector>

using namespace std;

bool rectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
    bool xOverlap =
        rec1[0] < rec2[2] &&
        rec2[0] < rec1[2];

    bool yOverlap =
        rec1[1] < rec2[3] &&
        rec2[1] < rec1[3];

    return xOverlap && yOverlap;
}

int main()
{
    vector<int> rec1;
    vector<int> rec2;

    int x;

    cout << endl;
    cout << "Enter the coordinates of Rectangle 1 in sequence (x1, y1, x2, y2)" << endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        rec1.push_back(x);
    }

    cout << endl;
    cout << "Enter the coordinates of Rectangle 2 in sequence (x1, y1, x2, y2)" << endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        rec2.push_back(x);
    }

    bool ans = rectangleOverlap(rec1, rec2);

    cout << endl;
    cout << "Rectangle overlap : " << ans << endl;
    cout << endl;

    return 0;
}