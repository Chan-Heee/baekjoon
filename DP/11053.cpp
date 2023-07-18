#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int score[1001];
    int dp[1001];
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (score[j] < score[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        res = max(res, dp[i]);
    }
    cout << res;
}