#include <iostream>

using namespace std;

void insertionSort( int arr[], int n)
{
    for( int i = 0; i < n; i++)
    {
        int j = i;
        while( j > 0 && arr[j-1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main()
{
    int n;

    cout <<  "Enter the number of elements : " << endl ;
    cin >> n;

    int arr[n];

    cout << "Enter the elements : " << endl;
    for ( int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "Sorted Array : " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << "    ";
    }
    cout << endl;

    return 0;
}