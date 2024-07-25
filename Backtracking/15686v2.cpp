#include <bits/stdc++.h>

using namespace std;

int n, m, ret = 100000;
int a[54][54];
vector<pair<int, int>> chicken;
int visited[15];
vector<pair<int, int>> home;
vector<int> pick;

void go(int cur, int last)
{
    if (cur == m)
    {
        int s = 0;
        for (int i = 0; i < home.size(); i++)
        {
            int d = 100000;
            for (int j = 0; j < pick.size(); j++)
            {
                d = min(d, (abs(home[i].first - chicken[pick[j]].first) + abs(home[i].second - chicken[pick[j]].second)));
            }
            s += d;
        }
        ret = min(s, ret);
        return;
    }

    for (int i = last + 1; i < chicken.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            pick.push_back(i);
            go(cur + 1, i);
            visited[i] = 0;
            pick.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
                chicken.push_back({i, j});
            else if (a[i][j] == 1)
                home.push_back({i, j});
        }
    go(0, -1);
    cout << ret;
}