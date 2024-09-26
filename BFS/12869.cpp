#include <bits/stdc++.h>

using namespace std;

int n, ans;
int scv[4];
int visited[61][61][61];
int attack[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}};

struct Status
{
    int a;
    int b;
    int c;
    int cnt;
};

queue<struct Status> q;
int main()
{
    cin >> n;
    struct Status s;
    for (int i = 0; i < n; i++)
        cin >> scv[i];

    s.a = scv[0];
    s.b = scv[1];
    s.c = scv[2];
    s.cnt = 0;

    q.push(s);
    while (!q.empty())
    {
        Status cur = q.front();
        if (cur.a <= 0 && cur.b <= 0 && cur.c <= 0)
        {
            ans = cur.cnt;
            break;
        }
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            Status next;
            next.a = max(0, cur.a - attack[i][0]);
            next.b = max(0, cur.b - attack[i][1]);
            next.c = max(0, cur.c - attack[i][2]);
            next.cnt = cur.cnt + 1;
            if (visited[next.a][next.b][next.c])
                continue;
            q.push(next);
            visited[next.a][next.b][next.c]++;
        }
    }
    cout << ans;
}