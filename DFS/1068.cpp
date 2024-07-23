#include <bits/stdc++.h>

using namespace std;

int n, tmp, d, ret, l;
vector<int> v[51];
int p[51];

int dfs(int l)
{
    int ret = 0;
    if (d == l)
        return 0;
    if (v[l].size() == 0)
        return 1;
    for (int i = 0; i < v[l].size(); i++)
    {
        if (p[v[l][i]] == -2)
            continue;

        ret += dfs(v[l][i]);
    }
    if (ret == 0)
        return 1;
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        p[i] = tmp;
        if (tmp == -1)
        {
            l = i;
            continue;
        }
        v[tmp].push_back(i);
    }
    cin >> d;
    p[d] = -2;
    cout << dfs(l);
}