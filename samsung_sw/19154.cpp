#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

vector<tuple<int, int, int>> v;
int n;
int result;
int dp[51][8];

int dfs(int cnt, int ability_mask)
{
    if (cnt == n)
    {
        if (ability_mask == 7)
            return 0;
        else
            return 2000000000;
    }

    if (dp[cnt][ability_mask] != -1)
        return dp[cnt][ability_mask];

    dp[cnt][ability_mask] = 2000000000;

    for (int k = 0; k < 3; k++)
    {
        int next_mask = ability_mask | (1 << k);

        dp[cnt][ability_mask] = min(dp[cnt][ability_mask], dfs(cnt + 1, next_mask) + get<0>(v[cnt * 3 + k]));
    }

    return dp[cnt][ability_mask];
}

int main(void)
{
    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        v.clear();

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cin >> dp[j][k];
            }
            for (int k = 0; k < 3; k++)
                v.push_back({(dp[j][(k + 1) % 3] + dp[j][(k + 2) % 3]), j, k});
        }
        if (n < 3)
        {
            cout << '#' << i + 1 << ' ' << -1 << '\n';
            continue;
        }
        memset(dp, -1, sizeof(dp));

        result = dfs(0, 0);
        cout << '#' << i + 1 << ' ' << result << '\n';
    }

    return 0;
}
