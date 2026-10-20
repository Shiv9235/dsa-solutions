#include <iostream>
#include <vector>

using namespace std;

long long avgWT(vector<int> bt)
{
    long long sum = 0;
    long long wt = 0;
    sort(bt.begin(), bt.end());
    for (int i = 1; i < bt.size(); i++)
    {
        sum += bt[i - 1];
        wt += sum;
    }

    return wt / bt.size();
}

int main()
{
    vector<int> bt = {4, 1, 3, 7, 2};

    cout << endl;
    cout << avgWT(bt) << endl;
    cout << endl;

    return 0;
}