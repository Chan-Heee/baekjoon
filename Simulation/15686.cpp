#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[51][51];
int MIN = 100000;
vector<pair<int, int>> result(15);
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

void dfs(int cnt, int last)
{
    if (cnt == m)
    {
        int sum = 0;
        for (int i = 0; i < home.size(); i++)
        {
            int dist = 10000;
            for (int j = 0; j < m; j++)
                dist = min(dist, (abs(result[j].first - home[i].first) + abs(result[j].second - home[i].second)));
            sum += dist;
        }
        MIN = min(MIN, sum);

        return;
    }
    for (int i = last + 1; i < chicken.size(); i++)
    {
        result[cnt] = chicken[i];
        dfs(cnt + 1, i);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                chicken.push_back({i, j});
            else if (map[i][j] == 1)
                home.push_back({i, j});
        }
    dfs(0, -1);
    cout << MIN;
}