#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string a, string b)
{
    int hash_a[26] = {0};
    int hash_b[26] = {0};

    if (a.size() != b.size())
    {
        return false;
    }

    for (int i = 0; i < a.size(); i++)
    {
        hash_a[a[i] - 'a']++;
        hash_b[b[i] - 'a']++;
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (hash_a[a[i] - 'a'] != hash_b[a[i] - 'a'])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "anagram";
    string t = "naoaram";

    bool ans = isAnagram(s, t);

    cout << endl;
    cout << ans << endl;
    cout << endl;

    return 0;
}