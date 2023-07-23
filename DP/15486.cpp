#include <iostream>

using namespace std;
int dp[1500001];
int T[1500001];
int P[1500001];

int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> T[i] >> P[i];
    if (T[n] == 1)
        dp[n] = P[n];

    for (int i = n - 1; i >= 1; i--)
    {
        if (T[i] + i > n + 1)
            dp[i] = dp[i + 1];
        else
        {
            dp[i] = max((P[i] + dp[i + T[i]]), dp[i + 1]);
        }
    }
    cout << dp[1];
}