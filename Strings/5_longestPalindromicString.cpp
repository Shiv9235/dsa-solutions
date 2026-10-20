#include <iostream>
#include <string>

using namespace std;

bool palindromeCheck(string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{

    string s = "cbbd";
    string answer;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string temp = s.substr(i, j - i + 1);
            if (palindromeCheck(temp))
            {
                if (answer.size() < temp.size())
                {
                    answer = temp;
                }
            }
        }
    }

    cout << endl;
    cout << "Largest substring which is palindrome : " << answer << endl;
    cout << endl;

    return 0;
}