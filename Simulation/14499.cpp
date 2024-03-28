#include <iostream>
#include <algorithm>

using namespace std;

int n, m, x, y, k;
int board[22][22];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dice[6];

void tumble(int comm)
{
    int nx = x + dx[comm - 1];
    int ny = y + dy[comm - 1];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        return;

    x = nx;
    y = ny;

    if (comm == 4)
    {
        swap(dice[0], dice[1]);
        swap(dice[1], dice[2]);
        swap(dice[2], dice[3]);
    }
    else if (comm == 3)
    {
        swap(dice[3], dice[2]);
        swap(dice[2], dice[1]);
        swap(dice[1], dice[0]);
    }
    else if (comm == 1)
    {
        swap(dice[4], dice[1]);
        swap(dice[1], dice[5]);
        swap(dice[3], dice[5]);
    }
    else
    {
        swap(dice[3], dice[4]);
        swap(dice[3], dice[1]);
        swap(dice[3], dice[5]);
    }

    if (board[nx][ny] == 0)
        board[nx][ny] = dice[1];

    else
    {
        dice[1] = board[nx][ny];
        board[nx][ny] = 0;
    }
    cout << dice[3] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < k; i++)
    {
        int comm;
        cin >> comm;

        tumble(comm);
    }
}