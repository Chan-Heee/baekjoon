#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
string s;
char board[5][5];
int selected[5][5];

void go(int y, int x, int cnt)
{
    if (cnt == n * m)
    {
        {
            int total = 0;

            // 가로 조각 계산
            for (int i = 0; i < n; i++)
            {
                string num = "";
                for (int j = 0; j < m; j++)
                {
                    if (selected[i][j] == 1) // 가로 조각
                    {
                        num = num + string(1, board[i][j]);
                    }
                    else // 세로 조각이 시작되면 지금까지 계산한 가로 조각 합산
                    {
                        if (!num.empty())
                            total += stoi(num);
                        num = "";
                    }
                }
                if (!num.empty())
                    total += stoi(num); // 라인의 마지막 가로 조각
            }

            // 세로 조각 계산
            for (int j = 0; j < m; j++)
            {
                string num = "";
                for (int i = 0; i < n; i++)
                {
                    if (selected[i][j] == 0) // 세로 조각
                    {
                        num = num + string(1, board[i][j]);
                    }
                    else // 가로 조각이 시작되면 지금까지 계산한 세로 조각 합산
                    {
                        if (!num.empty())
                            total += stoi(num);
                        num = "";
                    }
                }
                if (!num.empty())
                    total += stoi(num); // 컬럼의 마지막 세로 조각
            }
            ans = max(ans, total);
        }
        return;
    }

    if (x == m - 1)
    {
        selected[y + 1][0] = 1;
        go(y + 1, 0, cnt + 1);
        selected[y + 1][0] = 0;
        go(y + 1, 0, cnt + 1);
    }
    else
    {
        selected[y][x + 1] = 1;
        go(y, x + 1, cnt + 1);
        selected[y][x + 1] = 0;
        go(y, x + 1, cnt + 1);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            board[i][j] = s[j];
    }

    go(0, -1, 0);
    cout << ans;
}