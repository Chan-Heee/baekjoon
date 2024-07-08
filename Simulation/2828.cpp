#include <bits/stdc++.h>

using namespace std;
int n, m, k;
int goal;
int ans;

int main()
{
    cin >> n >> m >> k;
    int cur = 1;
    for (int i = 0; i < k; i++)
    {
        cin >> goal;
        if (goal <= cur + (m - 1) && goal >= cur)
            continue;
        if (goal > cur + (m - 1))
        {
            ans += (goal - (cur + (m - 1)));
            cur += (goal - (cur + (m - 1)));
        }
        else if (goal < cur)
        {
            ans += (cur - goal);
            cur -= (cur - goal);
        }
    }
    cout << ans;
}