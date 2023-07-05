#include <iostream>
#include <vector>

using namespace std;

int n;
int score[50][9];
int MAX = 0;
vector<int> order(9, -1);

int ft_total()
{
    int total = 0;
    int out = 0;
    int curr = 0;
    bool base[3] = {
        false,
    };
    for (int i = 0; i < n; i++)
    {
        while (out < 3)
        {
            if (score[i][order[curr]] == 0)
                out++;
            else if (score[i][order[curr]] == 1)
            {
                if (base[2])
                {
                    total++;
                    base[2] = false;
                }
                if (base[1])
                {
                    base[2] = true;
                    base[1] = false;
                }
                if (base[0])
                    base[1] = true;
                base[0] = true;
            }
            else if (score[i][order[curr]] == 2)
            {
                if (base[2])
                {
                    total++;
                    base[2] = false;
                }
                if (base[1])
                    total++;
                if (base[0])
                {
                    base[2] = true;
                    base[0] = false;
                }
                base[1] = true;
            }
            else if (score[i][order[curr]] == 3)
            {
                if (base[2])
                    total++;
                if (base[1])
                {
                    total++;
                    base[1] = false;
                }
                if (base[0])
                {
                    total++;
                    base[0] = false;
                }
                base[2] = true;
            }
            else
            {
                if (base[2])
                    total++;
                if (base[1])
                    total++;
                if (base[0])
                    total++;
                total++;
                for (int l = 0; l < 3; l++)
                    base[l] = false;
            }
            curr++;
            if (curr == 9)
                curr = 0;
        }
        out = 0;
        for (int k = 0; k < 3; k++)
            base[k] = false;
    }
    return total;
}
bool ft_check(int cnt)
{
    for (int i = 0; i < cnt; i++)
        if (order[i] == order[cnt])
            return false;
    return true;
}
void dfs(int cnt)
{
    if (cnt == 9)
    {
        if (ft_total() > MAX)
            MAX = ft_total();
        return;
    }

    for (int index = 1; index < 9; index++)
    {
        if (cnt == 3)
        {
            dfs(cnt + 1);
            break;
        }
        order[cnt] = index;
        if (ft_check(cnt))
            dfs(cnt + 1);
        order[cnt] = -1;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> score[i][j];
        }
    order[3] = 0;
    dfs(0);
    cout << MAX;
}