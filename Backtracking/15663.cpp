#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[10];
int print[10];
bool visited[10] = {
    false,
};

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << print[i] << " ";
        }
        cout << '\n';
        return;
    }
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && num[i] != last)
        {
            print[cnt] = num[i];
            last = print[cnt];
            visited[i] = true;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num, num + n);
    dfs(0);
}