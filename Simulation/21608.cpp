#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int t;
int n;
vector<vector<pair<int, int>>> board(20, vector<pair<int, int>>(20, {0, 0}));
int tmp[21][21];
int prefer[410][5];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

class person
{
public:
    int num;
    int x;
    int y;
    int z;
    int v;
};

queue<person> q;
int main()
{
    cin >> t;
    n = t * t;
    for (int i = 0; i < n; i++)
    {
        person p;
        cin >> p.num;
        cin >> p.x;
        cin >> p.y;
        cin >> p.z;
        cin >> p.v;
        q.push(p);
        prefer[p.num][0] = p.x;
        prefer[p.num][1] = p.y;
        prefer[p.num][2] = p.z;
        prefer[p.num][3] = p.v;
    }

    while (!q.empty())
    {
        person p = q.front();
        q.pop();
        int MAX = -1;
        pair<int, int> point = {0, 0};
        for (int j = 0; j < t; j++)
        {
            for (int k = 0; k < t; k++)
            {
                if (tmp[j][k])
                    continue;

                for (int m = 0; m < 4; m++)
                {
                    int nx = j + dx[m];
                    int ny = k + dy[m];

                    if (nx >= t || ny >= t || nx < 0 || ny < 0)
                        continue;

                    if (tmp[nx][ny] == p.x || tmp[nx][ny] == p.y || tmp[nx][ny] == p.z || tmp[nx][ny] == p.v)
                        board[j][k].second++;

                    if (!tmp[nx][ny])
                        board[j][k].first++;
                }
                if (board[j][k].second > MAX)
                {
                    MAX = board[j][k].second;
                    point = {j, k};
                }
                else if (board[j][k].second == MAX)
                {
                    if (board[j][k].first > board[point.first][point.second].first)
                        point = {j, k};
                }
            }
        }
        tmp[point.first][point.second] = p.num;
        for (int a = 0; a < t; a++)
            for (int b = 0; b < t; b++)
                board[a][b] = {0, 0};
    }

    int sum = 0;
    for (int i = 0; i < t; i++)
    {

        for (int j = 0; j < t; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= t || ny >= t || nx < 0 || ny < 0)
                    continue;

                if (tmp[nx][ny] == prefer[tmp[i][j]][0] || tmp[nx][ny] == prefer[tmp[i][j]][1] || tmp[nx][ny] == prefer[tmp[i][j]][2] || tmp[nx][ny] == prefer[tmp[i][j]][3])
                    cnt++;
            }
            sum = sum + ((cnt > 0) ? pow(10, cnt - 1) : 0);
        }
    }
    cout << sum;
}
