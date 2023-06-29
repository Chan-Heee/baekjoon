#include <iostream>

using namespace std;

int n, m;
bool visited[10] = {
    false,
};
int print[10] = {0};

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < cnt; i++)
            cout << print[i] << " ";
        cout << '\n';
        return;
    }
    int num = 1;
    while (num <= n)
    {
        print[cnt] = num;
        visited[num] = true;
        if (cnt == 0 || (visited[num - 1] == false && (print[cnt - 1] < print[cnt])))
            dfs(cnt + 1);
        visited[num] = false;
        num++;
    }
}

int main()
{
    cin >> n >> m;
    dfs(0);
}