#include <bits/stdc++.h>

using namespace std;

int n;
string name, stat;
map<string, string, greater<>> m;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> stat;
        m[name] = stat;
    }
    for (auto k : m)
    {
        if (k.second == "enter")
            cout << k.first << '\n';
    }
}