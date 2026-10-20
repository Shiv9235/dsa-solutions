#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i;
        while (j > 0 && nums[j - 1] > nums[j])
        {
            swap(nums[j - 1], nums[j]);
            j--;
        }
    }
}

void selectionSort(vector<int> &nums)
{

    for (int i = 0; i < nums.size(); i++)
    {
        int key = i;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] < nums[key])
            {
                key = j;
            }
        }
        swap(nums[key], nums[i]);
    }
}

void printVector(vector<int> &nums)
{
    cout << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "      ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[j - 1])
            {
                swap(nums[j], nums[j - 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    vector<int> nums = {2, 5, 1, 6, 7, 2, 4, 6, 5, 1, 3, 4};

    bubbleSort(nums);
    printVector(nums);

    return 0;
}