#include <bits/stdc++.h>

using namespace std;

int t, n;
map<string, int> m;
string s;
int ans = 1;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            int pos = s.find(" ");
            string category = s.substr(pos + 1);
            m[category]++;
        }
        for (auto pair : m)
            ans *= (pair.second + 1);

        cout << ans - 1 << '\n';
        ans = 1;
        m.clear();
    }
}