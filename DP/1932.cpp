#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int score[501][501];
    int dp[501][501];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            cin >> score[i][j];
        }
    dp[1][1] = score[1][1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                dp[i][j] = dp[i - 1][j] + score[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + score[i][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + score[i][j];
        }
    }
    int MAX = -1;
    for (int i = 1; i <= n; i++)
    {
        if (MAX < dp[n][i])
            MAX = dp[n][i];
    }
    cout << MAX;
}