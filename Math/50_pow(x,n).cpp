#include <iostream>

using namespace std;

double exponent(double base, double pow)
{
    if (pow == 0)
    {
        return 1;
    }
    else if (pow > 0)
    {
        return base * exponent(base, pow - 1);
    }
    else if (pow < 0)
    {
        return (1 / (base * exponent(base, pow + 1)));
    }
    return 0;
}

int main()
{
    double ans = exponent(2.00000, -4);

    cout << endl;
    cout << ans << endl;
    cout << endl;

    return 0;
}