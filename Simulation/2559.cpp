#include <bits/stdc++.h>

using namespace std;

int n, k;
int t[100004];
int ans;

int main()
{
    cin >> n >> k;

    cin >> t[0];
    for (int i = 1; i < n; i++)
    {
        cin >> t[i];
        t[i] += t[i - 1];
    }

    ans = t[k - 1];
    for (int i = 1; i <= n - k; i++)
    {
        ans = max(ans, (t[i + k - 1] - t[i - 1]));
    }
    cout << ans;
}