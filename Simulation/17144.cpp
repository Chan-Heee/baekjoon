#include <iostream>

using namespace std;

int board[51][55];
int air[2];
int near[51][55];
int result[51][55];

int main()
{
    int r, c, t;
    int idx = 0;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == -1)
                air[idx++] = i;
        }

    while (t--)
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                result[i][j] = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= r || ny >= c)
                        continue;

                    if (ny == 0 && (nx == air[0] || nx == air[1]))
                        continue;
                    result[nx][ny] = result[nx][ny] + (board[i][j] / 5);
                    near[i][j]++;
                }
            }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                board[i][j] = board[i][j] + result[i][j] - (near[i][j]) * (board[i][j] / 5);
        }
        for (int i = 0; i <= air[0]; i++)
            for (int j = 0; j < c; j++)
            {
                if (i != 0 && j == 0)
                    result[i][j] = board[i - 1][j];
                else if (j != 0 && i == air[0])
                    result[i][j] = (j == 1) ? 0 : board[i][j - 1];
                else if (i != air[0] && j == c - 1)
                    result[i][j] = board[i + 1][j];
                else if (j != c - 1 && i == 0)

                    result[i][j] = board[i][j + 1];

                else
                    result[i][j] = board[i][j];
            }
        result[air[0]][0] = -1;
        for (int i = air[1]; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                if (i != r - 1 && j == 0)
                    result[i][j] = board[i + 1][j];
                else if (j != 0 && i == air[1])
                    result[i][j] = (j == 1) ? 0 : board[i][j - 1];
                else if (i != air[1] && j == c - 1)
                    result[i][j] = board[i - 1][j];
                else if (j != c - 1 && i == r - 1)

                    result[i][j] = board[i][j + 1];

                else
                    result[i][j] = board[i][j];
            }
        result[air[1]][0] = -1;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                board[i][j] = result[i][j];
                near[i][j] = 0;
            }
    }

    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            sum = sum + board[i][j];
    }
    cout << sum + 2;
}