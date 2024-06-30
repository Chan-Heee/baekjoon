#include <bits/stdc++.h>

using namespace std;
string s;
map<string, int> m1;
map<int, string> m2;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        m1[s] = i;
        m2[i] = s;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> s;

        if (atoi(s.c_str()) == 0)
            cout << m1[s] << '\n';

        else
            cout << m2[atoi(s.c_str())] << '\n';
    }
}