#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
string s[1004];
string ret;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++)
    {
        int t = 0, a = 0, c = 0, g = 0;
        int high = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j][i] == 'T')
                t++;
            else if (s[j][i] == 'A')
                a++;
            else if (s[j][i] == 'C')
                c++;
            else if (s[j][i] == 'G')
                g++;
        }
        high = max({t, a, c, g});
        ans += n - high;
        if (a == high)
            ret.push_back('A');
        else if (c == high)
            ret.push_back('C');
        else if (g == high)
            ret.push_back('G');
        else
            ret.push_back('T');
    }
    cout << ret << '\n'
         << ans;
}