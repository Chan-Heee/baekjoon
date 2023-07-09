#include <iostream>

using namespace std;

int main()
{
    int n;
    int score[301];
    int dp[301] = {
        0,
    };
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> score[i];

    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    for (int i = 3; i <= n; i++)
    {
        if ((dp[i - 2] + score[i]) > (dp[i - 3] + score[i - 1] + score[i]))

            dp[i] = dp[i - 2] + score[i];

        else
            dp[i] = dp[i - 3] + score[i - 1] + score[i];
    }
    cout << dp[n];
}