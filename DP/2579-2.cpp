#include <iostream>

using namespace std;

int main()
{
    int dp[301][3] = {
        0,
    };
    int n;
    int score[301] = {
        0,
    };
    cin >> n;
    int j = 1;
    for (int i = 1; i <= n; i++)
        cin >> score[i];
    dp[1][1] = score[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][1] = max(dp[i - 2][1] + score[i], dp[i - 2][2] + score[i]);
        dp[i][2] = dp[i - 1][1] + score[i];
    }
    cout << max(dp[n][1], dp[n][2]);
}