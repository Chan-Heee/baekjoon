#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
string s;
vector<string> v;
int visited[26];

void go(int cnt, int last)
{
    if (cnt == k)
    {
        int ret = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int c = 0;
            for (int j = 0; j < v[i].size(); j++)
            {
                if (!visited[v[i][j] - 'a'])
                    break;
                else
                    c++;
            }
            if (c == v[i].size())
                ret++;
        }
        ans = max(ret, ans);
        return;
    }
    for (int i = last + 1; i < 26; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            go(cnt + 1, i);
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    if (k < 5)
    {
        cout << 0;
        return 0;
    }
    visited[0] = 1;
    visited[2] = 1;
    visited[8] = 1;
    visited[13] = 1;
    visited[19] = 1;
    go(5, -1);
    cout << ans;
}

// 32 16

// 32 8 4

// 32 8 2 2 ->
