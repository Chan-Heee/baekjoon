#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int score[1001];
    int dp[1001];
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
    }
    score[0] = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = score[i];
        for (int j = 1; j < i; j++)
        {
            if ((score[i] > score[j]) && (dp[i] < dp[j] + score[i]))
                dp[i] = dp[j] + score[i];
        }
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}
