#include <iostream>

using namespace std;

int n;
int num;
int s[20][20];
int MIN = 100000;
int team1[21] = {
    0,
};
int team2[21];
bool visited[21] = {
    false,
};

void dfs(int k, int cnt)
{
    if (cnt == num)
    {
        int j = 0;
        bool check[21] = {
            false,
        };
        for (int i = 0; i < num; i++)
            check[team1[i]] = true;
        for (int i = 1; i <= n; i++)
        {
            if (j == num)
                break;
            if (!check[i])
            {
                team2[j] = i;
                j++;
            }
        }
        int team1_t = 0;
        int team2_t = 0;
        for (int i = 0; i < num - 1; i++)
            for (int j = i + 1; j < num; j++)
            {
                team1_t = team1_t + s[team1[i] - 1][team1[j] - 1] + s[team1[j] - 1][team1[i] - 1];
                team2_t = team2_t + s[team2[i] - 1][team2[j] - 1] + s[team2[j] - 1][team2[i] - 1];
            }
        int sub;
        sub = abs(team1_t - team2_t);
        if (sub < MIN)
            MIN = sub;
        return;
    }
    for (int idx = k; idx <= n; idx++)
    {
        team1[cnt] = idx;
        if (!visited[idx])
        {
            visited[idx] = true;
            dfs(idx, cnt + 1);
        }
        visited[idx] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    num = n / 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    dfs(1, 0);
    cout << MIN;
}