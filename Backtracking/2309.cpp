#include <bits/stdc++.h>

using namespace std;
vector<int> height;
vector<int> ans;
int sum;
bool flag;

void dfs(int cnt, int last)
{
    if ((cnt == 7) && (sum == 100) && !flag)
    {
        sort(ans.begin(), ans.end());
        for (int i : ans)
        {
            cout << i << '\n';
        }
        flag = true;
        return;
    }

    for (int i = last + 1; i < 9; i++)
    {
        if (!flag)
        {
            sum += height[i];
            ans.push_back(height[i]);
            dfs(cnt + 1, i);
            sum -= height[i];
            ans.pop_back();
        }
    }
}

int main()
{
    for (int tmp, i = 0; i < 9; i++)
    {
        cin >> tmp;
        height.push_back(tmp);
    }
    dfs(0, -1);
}