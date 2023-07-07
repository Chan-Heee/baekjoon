#include <iostream>
#include <string>
#include <vector>

using namespace std;

string map[6][6];
vector<pair<int, int>> v;
bool flag = false;
int n;

bool ft_check()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == "T")
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    if (map[k][j] == "O")
                        break;
                    if (map[k][j] == "S")
                        return false;
                }
                for (int k = i + 1; k < n; k++)
                {
                    if (map[k][j] == "O")
                        break;
                    if (map[k][j] == "S")
                        return false;
                }
                for (int k = j - 1; k >= 0; k--)
                {
                    if (map[i][k] == "O")
                        break;
                    if (map[i][k] == "S")
                        return false;
                }
                for (int k = j + 1; k < n; k++)
                {
                    if (map[i][k] == "O")
                        break;
                    if (map[i][k] == "S")
                        return false;
                }
            }
        }
    return true;
}
void dfs(int cnt, int index)
{
    if (cnt == 3)
    {
        if (ft_check())
            flag = true;
        return;
    }
    while (index < v.size())
    {
        map[v[index].first][v[index].second] = "O";
        dfs(cnt + 1, index + 1);
        map[v[index].first][v[index].second] = "X";
        index++;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == "X")
                v.push_back(make_pair(i, j));
        }
    dfs(0, 0);
    if (flag)
        cout << "YES";
    else
        cout << "NO";
}
