#include <bits/stdc++.h>

using namespace std;

int n, ans = 1000000000, mp, mf, ms, mv;
int board[20][8];
map<int, vector<vector<int>>> m;

void go(int cnt)
{
    int p_sum = 0, f_sum = 0, s_sum = 0, v_sum = 0, sum = 0;
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        if (cnt & (1 << i))
        {
            p_sum += board[i][0];
            f_sum += board[i][1];
            s_sum += board[i][2];
            v_sum += board[i][3];
            sum += board[i][4];
            tmp.push_back(i);
        }
    }
    if (p_sum >= mp && f_sum >= mf && s_sum >= ms && v_sum >= mv && ans >= sum)
    {
        ans = sum;
        m[ans].push_back(tmp);
    }
}

int main()
{
    cin >> n >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    for (int i = 0; i < (1 << n); i++)
        go(i);
    if (ans == 1000000000)
    {
        cout << -1;
        return 0;
    }
    sort(m[ans].begin(), m[ans].end());
    cout << ans << '\n';
    for (int a : m[ans][0])
        cout << a + 1 << " ";
}