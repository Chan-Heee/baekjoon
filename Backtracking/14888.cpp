#include <iostream>
#include <vector>

using namespace std;

int n;
int Max = -1000000000;
int Min = 1000000000;
vector<int> num(11, 0);
vector<int> arith(4, 0);

int math(int sum, int i, int cnt)
{
    if (i == 0)
        sum = sum + num[cnt + 1];
    else if (i == 1)
        sum = sum - num[cnt + 1];
    else if (i == 2)
        sum = sum * num[cnt + 1];
    else
        sum = sum / num[cnt + 1];
    return sum;
}

void dfs(int cnt, int sum)
{
    if (cnt == n - 1)
    {
        if (sum > Max)
            Max = sum;
        if (sum <= Min)
            Min = sum;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int tmp_sum;
        arith[i]--;
        tmp_sum = math(sum, i, cnt);
        if (arith[i] >= 0)
            dfs(cnt + 1, tmp_sum);
        arith[i]++;
    }
}

int main()
{
    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        num[i] = tmp;
    }
    cin >> arith[0] >> arith[1] >> arith[2] >> arith[3];
    dfs(0, num[0]);
    cout << Max << "\n";
    cout << Min;
}