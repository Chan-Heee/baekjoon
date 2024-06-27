#include <bits/stdc++.h>

using namespace std;
int ans[500];

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        int k = s[i];
        ans[k]++;
    }
    for (int i = 'a'; i <= 'z'; i++)
        cout << ans[i] << " ";
}