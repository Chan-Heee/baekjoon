#include <iostream>

using namespace std;

int n, m;
int print[8] = {
    0,
};

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << print[i] << " ";
        cout << "\n";
        return;
    }
    int num = 1;
    while (num <= n)
    {
        print[cnt] = num++;
        dfs(cnt + 1);
    }
}

int main()
{
    cin >> n >> m;
    dfs(0);
}