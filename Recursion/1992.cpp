#include <bits/stdc++.h>

using namespace std;

int n;
int a[68][68];
string s;

bool check(int n, int y, int x)
{
    for (int i = y; i < y + n; i++)
        for (int j = x; j < x + n; j++)
        {
            if (a[y][x] != a[i][j])
                return false;
        }
    cout << a[y][x];
    return true;
}

void dfs(int n, int y, int x)
{
    if (!check(n, y, x))
    {
        cout << "(";
        dfs(n / 2, y, x);
        dfs(n / 2, y, x + n / 2);
        dfs(n / 2, y + n / 2, x);
        dfs(n / 2, y + n / 2, x + n / 2);
        cout << ")";
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = s[j] - '0';
    }
    dfs(n, 0, 0);
}