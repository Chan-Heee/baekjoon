#include <bits/stdc++.h>

using namespace std;

int n, k;
int psum[100004];
int ans = -10000004;

int main()
{
    cin >> n >> k;
    for (int i = 1, tmp; i <= n; i++)
    {
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }

    for (int i = k; i <= n; i++)
    {
        ans = max(ans, psum[i] - psum[i - k]);
    }
    cout << ans;
}