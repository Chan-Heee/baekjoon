#include <bits/stdc++.h>

using namespace std;

int n;
int num[10];
int visited[10];
int result[10];
int ans = 0;

void dfs(int here)
{
    if (here == n)
    {
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += abs(result[i] - result[i + 1]);
        }
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            result[here] = num[i];
            visited[i]++;
            dfs(here + 1);
            visited[i] = 0;
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
        cin >> num[i];

    dfs(0);
    cout << ans;
}