#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // Brute Force Algo : 
    // 1. first make two vectors in which one will have all negative and other all positive
    // 2. clear out the nums array
    // 3. at even indices of num there will be positive intger and at odd indices negative one 
    // this will satisfy all the contraints that are applied on the question

    vector<int> nums = {-1, 1};
    int n = nums.size();
    
    vector<int> pos, neg;
 
    // separating values 
    for (int i = 0; i < n; i++)
    {
        if(nums[i] < 0)
        {
            neg.push_back(nums[i]);
        }
        else
        {
            pos.push_back(nums[i]);
        }
    }
    // clearing nums
    nums.clear();
    int pos_itr = 0; 
    int neg_itr = 0;

    // adding back as per the need
    for(int i = 0; i < n; i++)
    {

        if (i % 2 == 0 && pos_itr < pos.size())
        {
            nums.push_back(pos[pos_itr]);
            pos_itr++;
        }
        else if (i % 2 != 0 && neg_itr < neg.size())
        {
            nums.push_back(neg[neg_itr]);
            neg_itr++;
        }
    }

    cout << endl;
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    cout << endl;


    return 0;
}