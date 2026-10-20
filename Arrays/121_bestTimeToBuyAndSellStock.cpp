#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> prices = {7,6,4,3,1};
    int buy = prices[0];
    int profit = 0;

    for ( int i = 1; i < prices.size(); i ++)
    {
        buy = min(buy, prices[i]);
        profit = max(profit, prices[i] - buy);
    }

    cout << "Profit : " << profit << endl;

    return 0;
}
