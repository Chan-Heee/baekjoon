#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
char alpha[16];
char print[16];

void dfs(int cnt)
{
    if (cnt == n)
    {
        int flag1 = 0;
        int flag2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (print[i] == 'a' || print[i] == 'e' || print[i] == 'i' || print[i] == 'o' || print[i] == 'u')
                flag1++;
            else
                flag2++;
        }
        if (flag1 >= 1 && flag2 >= 2)
        {
            for (int i = 0; i < n; i++)
            {
                cout << print[i];
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 0; i < m; i++)
    {
        if (cnt == 0 || alpha[i] > print[cnt - 1])
        {
            print[cnt] = alpha[i];
            dfs(cnt + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> alpha[i];
    }
    sort(alpha, alpha + m);
    dfs(0);
}