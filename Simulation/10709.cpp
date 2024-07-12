#include <bits/stdc++.h>

using namespace std;

int h, w;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> w;
    while (h--)
    {
        cin >> s;
        int idx = 0;
        for (idx = 0; idx < s.size() && s[idx] != 'c'; idx++)
            cout << -1 << ' ';
        int cnt = 0;
        for (int i = idx; i < s.size(); i++)
        {
            if (s[i] == 'c')
            {
                cout << '0' << ' ';
                cnt = 0;
            }
            else if (s[i] == '.')
                cout << ++cnt << ' ';
        }
    }
    cout << '\n';
}