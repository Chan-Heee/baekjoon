#include <iostream>
#include <vector>

using namespace std;

vector<int> k;
vector<vector<int>> num(10000);
int cur_k;
int print[15];

void dfs(int cnt, int last)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << print[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = last + 1; 6 - cnt <= num[cur_k].size() - i; i++)
    {
        print[cnt] = num[cur_k][i];
        dfs(cnt + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    while (1)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
            break;
        k.push_back(tmp);
        for (int i = 0, j; i < tmp; i++)
        {
            cin >> j;
            num[n].push_back(j);
        }
        n++;
    }

    for (int i = 0; i < k.size(); i++)
    {
        dfs(0, -1);
        if (i != k.size() - 1)
            cout << "\n";
        cur_k++;
    }
}