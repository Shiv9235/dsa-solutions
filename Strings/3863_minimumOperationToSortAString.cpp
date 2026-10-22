#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minOperations(string s)
{
    int n = s.length();

    // Case 1: Already sorted
    if (is_sorted(s.begin(), s.end()))
        return 0;

    // Case 2: Length 2 and unsorted
    if (n == 2)
        return -1;

    char mn = *min_element(s.begin(), s.end());
    char mx = *max_element(s.begin(), s.end());

    // Case 3: One operation is enough
    if (s[0] == mn || s[n - 1] == mx)
        return 1;

    // Case 4: Check the middle characters
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == mn || s[i] == mx)
            return 2;
    }

    // Case 5: All other unsorted strings
    return 3;
}

int main()
{
    string s = "cba";
    int ans = minOperations(s);

    cout << endl;
    cout << s << " Min Operation Required : " << ans << endl;
    cout << endl;

    return 0;
}