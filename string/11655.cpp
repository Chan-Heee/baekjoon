#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = 'a' + (s[i] + 13 - 'a') % 26;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = 'A' + (s[i] + 13 - 'A') % 26;
        }
    }
    cout << s;
}