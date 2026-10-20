#include <iostream.
using namespace std;

int main()
{
    int n;

    cout << "How many rows do you want ???";
    cin >> n;

    int arr[n] = {0};
    arr[0] = 1;

    for ( int i = 0; i < n; i ++ )
    {
        cout << arr[i] + arr[i+1];
    }
    



    return 0;
}
