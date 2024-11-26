#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt = 0, origin_room = 0, after_room = 0;
int wall[54][54];
int room_id[54][54];
vector<int> room_size; // 각 방의 크기 저장
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

void bfs(int y, int x, int id)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    room_id[y][x] = id;
    int size = 0;

    while (!q.empty())
    {
        auto [cy, cx] = q.front();
        q.pop();
        size++;

        for (int d = 0; d < 4; d++)
        {
            if (wall[cy][cx] & (1 << d))
                continue; // 벽 존재 시 패스
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (room_id[ny][nx] != -1)
                continue;

            room_id[ny][nx] = id;
            q.push({ny, nx});
        }
    }
    room_size.push_back(size);            // 현재 방 크기 저장
    origin_room = max(origin_room, size); // 최대 방 크기 갱신
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> wall[i][j];

    memset(room_id, -1, sizeof(room_id)); // 방 ID 초기화

    // 모든 방 탐색 및 ID 할당
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (room_id[i][j] == -1)
            {
                bfs(i, j, cnt++); // 새로운 방 탐색
            }
        }
    }

    // 벽 제거 후 최대 방 크기 계산
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int d = 0; d < 4; d++)
            {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                    continue;

                int id1 = room_id[i][j];
                int id2 = room_id[ny][nx];

                if (id1 != id2)
                { // 다른 방이면 합산
                    after_room = max(after_room, room_size[id1] + room_size[id2]);
                }
            }
        }
    }

    cout << cnt << '\n'
         << origin_room << '\n'
         << after_room << '\n';
    return 0;
}
