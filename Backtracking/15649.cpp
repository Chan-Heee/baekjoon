#include <iostream>

using namespace std;

bool ft_check(int *print, int cnt, int num)
{
    bool k;
    for (int i = 0; i < cnt; i++)
    {
        if (print[i] == num)
            return false;
    }
    return true;
}
void ft_permutation(int cnt, int num, int *print, int m, int n)
{
    num = 1;
    if (cnt == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << print[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        while (num <= m)
        {
            print[cnt] = num;
            if (ft_check(print, cnt, num))
                ft_permutation(cnt + 1, num, print, m, n);
            num++;
        }
    }
}

int main()
{
    int m, n;

    cin >> m >> n;
    int print[8] = {0};
    ft_permutation(0, 1, print, m, n);
}