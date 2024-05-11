#include <iostream>
#include <deque>

using namespace std;

int n;
int k;
int l;
int cur_time = -1;
int board[102][102];
int dir[10001];
int cur_dir = 1; // 0 북 1 동 2 남 3 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    cin >> n;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int x;
        int y;
        cin >> x;
        cin >> y;
        board[x - 1][y - 1] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int t;
        char d;
        cin >> t;
        cin >> d;
        dir[t] = d;
    }
    board[0][0] = 2;
    deque<pair<int, int>> snake;
    snake.push_back({0, 0});
    pair<int, int> head;
    pair<int, int> tail;

    head = snake.front();
    tail = snake.back();

    while (1)
    {
        cur_time++;
        if (dir[cur_time] == 'D')
            cur_dir = (cur_dir + 1) % 4;
        else if (dir[cur_time] == 'L')
            cur_dir = (cur_dir + 3) % 4;

        int nx = head.first + dx[cur_dir];
        int ny = head.second + dy[cur_dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 2)
        {
            cout << cur_time + 1;
            break;
        }
        if (board[nx][ny] == 1)
        {
            snake.push_front({nx, ny});
            board[nx][ny] = 2;
            head.first = snake.front().first;
            head.second = snake.front().second;
            continue;
        }
        else
        {
            snake.push_front({nx, ny});
            board[nx][ny] = 2;
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
            head.first = snake.front().first;
            head.second = snake.front().second;
            tail.first = snake.back().first;
            tail.second = snake.back().second;
        }
    }
}