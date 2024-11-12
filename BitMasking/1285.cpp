#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int ans;
bool board[24][24];

void dfs(int cur, int cnt, int last, int isRow)
{
    if (cur == cnt)
    {
        int t_sum = 0;
        if (isRow)
        {
            for (int i = 0; i < n; i++)
            {
                int h_sum = 0;
                for (int j = 0; j < n; j++)
                {
                    if (!board[j][i])
                        h_sum++;
                }
                (h_sum < n - h_sum) ? t_sum += h_sum : t_sum += n - h_sum;
            }
            ans = min(ans, t_sum);
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int h_sum = 0;
                for (int j = 0; j < n; j++)
                {
                    if (!board[i][j])
                        h_sum++;
                }
                (h_sum < n - h_sum) ? t_sum += h_sum : t_sum += n - h_sum;
            }
            ans = min(ans, t_sum);
        }
        return;
    }
    for (int i = last + 1; i < n; i++)
    {

        if (isRow)
        {
            for (int a = 0; a < n; a++)
                board[i][a] = !board[i][a];
            dfs(cur + 1, cnt, i, isRow);
            for (int a = 0; a < n; a++)
                board[i][a] = !board[i][a];
        }
        else
        {
            for (int a = 0; a < n; a++)
                board[a][i] = !board[a][i];
            dfs(cur + 1, cnt, i, isRow);
            for (int a = 0; a < n; a++)
                board[a][i] = !board[a][i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'T')
            {
                ans++;
                board[i][j] = true;
            }
            else
                board[i][j] = false;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        dfs(0, i, -1, 1);
    }
    for (int i = 0; i <= n; i++)
    {
        dfs(0, i, -1, 0);
    }
    cout << ans;
}