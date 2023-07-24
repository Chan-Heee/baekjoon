#include <iostream>

using namespace std;

int main()
{
    int n;
    int in[100001];
    long dp[101];
    int MAX = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        if (MAX < in[i])
            MAX = in[i];
    }
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= MAX; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[in[i]] << '\n';
    }
}