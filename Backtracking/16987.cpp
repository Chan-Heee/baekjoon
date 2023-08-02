#include <iostream>
#include <algorithm>

using namespace std;

int n;
int weight[8];
int MAX;

bool ft_check(int *s, int cnt)
{
    for (int i = 0; i < n; i++)
    {
        if (i == cnt)
            continue;
        if (s[i] > 0)
            return false;
    }
    return true;
}
void dfs(int cnt, int s[])
{
    if (cnt == n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] <= 0)
                count++;
        }
        MAX = max(count, MAX);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[cnt] <= 0 || ft_check(s, cnt))
        {
            dfs(cnt + 1, s);
            break;
        }
        if (i != cnt && s[i] > 0)
        {
            s[cnt] = s[cnt] - weight[i];
            s[i] = s[i] - weight[cnt];
            dfs(cnt + 1, s);
            s[cnt] = s[cnt] + weight[i];
            s[i] = s[i] + weight[cnt];
        }
    }
}

int main()
{
    cin >> n;
    int duality[8];
    for (int i = 0; i < n; i++)
    {

        cin >> duality[i] >> weight[i];
    }
    dfs(0, duality);
    cout << MAX;
}