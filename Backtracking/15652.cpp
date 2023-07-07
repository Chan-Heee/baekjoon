#include <iostream>

using namespace std;
int n, m;
int print[8];

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << print[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        print[cnt] = i;
        if (cnt == 0 || print[cnt] >= print[cnt - 1])
            dfs(cnt + 1);
    }
}

int main()
{
    cin >> n >> m;
    dfs(0);
}