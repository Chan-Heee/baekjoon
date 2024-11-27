#include <bits/stdc++.h>

using namespace std;

int m, num, ans;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++)
    {
        getline(cin, s);
        stringstream ss(s);
        ss >> s >> num;
        if (s == "add")
            ans |= 1 << (num - 1);
        else if (s == "check")
            (ans & (1 << (num - 1))) ? cout << 1 << '\n' : cout << 0 << '\n';
        else if (s == "remove")
            ans &= ~(1 << (num - 1));
        else if (s == "toggle")
            ans ^= 1 << (num - 1);
        else if (s == "empty")
            ans = 0;
        else if (s == "all")
            ans = 0b11111111111111111111;
    }
}