#include <iostream>

using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                minIndex = j;
            }

            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements : " << endl;
    cin >> n;

    int arr[n];

    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Sorted Array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "    ";
    }
    cout << endl;

    return 0;
}