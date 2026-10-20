#include <iostream>
#include <vector>
#include <string>

using namespace std;

string maxSumOfSquare(int num, int sum)
{
    if (sum < 1 && sum > (9 * num))
        return "";

    string ans = "";

    while (num)
    {
        int digit = min(9, sum);
        sum -= digit;

        ans += to_string(digit);
        num--;
    }

    return ans;
}

int main()
{
    int num, sum;

    cout << endl;
    cout << "Enter the number of Digits : ";
    cin >> num;
    cout << "Enter the sum of the Digits : ";
    cin >> sum;

    string ans = maxSumOfSquare(num, sum);

    cout << endl;
    cout << ans;
    cout << endl;

    return 0;
}
