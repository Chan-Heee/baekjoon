#include <iostream>
#include <vector>

using namespace std;

int num = 0;
int m;
vector<int> v(15, -1);
bool ft_check(int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        if (v[i] == v[cnt])
            return false;
        if ((cnt - i) == (v[cnt] - v[i]))
            return false;
        if ((cnt - i) == (v[i] - v[cnt]))
            return false;
    }
    return true;
}

void ft_nqueen(int cnt)
{
    if (cnt == m)
    {
        num++;
        return;
    }
    for (int i = 0; i < m; i++)
    {
        v[cnt] = i;
        if (ft_check(cnt))
            ft_nqueen(cnt + 1);
    }
    return;
}
int main()
{
    cin >> m;
    ft_nqueen(0);
    cout << num;
}