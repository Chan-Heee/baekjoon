#include <iostream>
#include <vector>

using namespace std;

int map[9][9];
int flag = 0;
vector<pair<int, int>> v;
int n = 0;

bool ft_check(pair<int, int> p)
{
    for (int i = 0; i < 9; i++)
    {
        if (p.first != i && map[p.first][p.second] == map[i][p.second])
            return false;
        if (p.second != i && map[p.first][p.second] == map[p.first][i])
            return false;
    }
    int div1, div2;
    div1 = p.first / 3;
    div2 = p.second / 3;
    for (int i = div1 * 3; i < div1 * 3 + 3; i++)
        for (int j = div2 * 3; j < div2 * 3 + 3; j++)
            if (map[i][j] == map[p.first][p.second] && (i != p.first && j != p.second))
                return false;
    return true;
}
void dfs(int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << map[i][j] << " ";
            cout << "\n";
        }
        flag = 1;
        return;
    }
    int num = 1;

    while (num <= 9)
    {
        map[v[cur].first][v[cur].second] = num++;
        if (ft_check(v[cur]))
            dfs(cur + 1);
        if (flag == 1)
            return;
    }
    map[v[cur].first][v[cur].second] = 0;
    return;
}

int main()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
            {
                v.push_back(make_pair(i, j));
                n++;
            }
        }
    dfs(0);
}