#include <bits/stdc++.h>

using namespace std;

int n, pos;
string s;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> s;
        while ((pos = s.find("()")) != string ::npos)
            s.erase(pos, 2);
        (s.size()) ? cout << "NO" : cout << "YES";
        cout << '\n';
    }
}