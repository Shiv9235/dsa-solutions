#include <iostream>
#include <string>

using namespace std;

string convert2binary(int x)
{
    string res = "";

    while (x != 0)
    {
        if (x % 2 == 1)
            res += '1';
        else
            res += '0';

        x = x / 2;
    }
    reverse(res.begin(), res.end());

    return res;
}

int convert2decimal(string x)
{
    int p2 = 1;
    int sum = 0;
    int n = x.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (x[i] == '1')
        {
            sum += p2;
        }
        p2 *= 2;
    }

    return sum;
}

int main()
{
    string x;

    cout << endl;
    cout << "Enter a number : ";
    cin >> x;

    cout << x << " in Binary : " << convert2decimal(x) << endl;
    cout << endl;

    return 0;
}