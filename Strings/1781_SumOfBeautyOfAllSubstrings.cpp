#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    string s = "xzvfsppsjfbxdwkqe";

    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int hash[26] = {0};
        for (int j = i; j < s.size(); j++)
        {
            // string temp;
            hash[s[j] - 'a']++;
            string temp = s.substr(i, j - i + 1);

            if (temp.size() >= 2)
            {
                int maximum = 0;
                int minimum = INT_MAX;
                for (int k = 0; k < 26; k++)
                {
                    if (hash[k] > 0)
                    {
                        maximum = max(maximum, hash[k]);
                        minimum = min(minimum, hash[k]);
                    }
                }
                answer += (maximum - minimum);
            }
        }
    }
    cout << endl;
    cout << answer << endl;
    cout << endl;

    return 0;
}