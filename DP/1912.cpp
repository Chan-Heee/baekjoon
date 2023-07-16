#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int score[100001];
    int dp[100001];
    for (int i = 1; i <= n; i++)
        cin >> score[i];
    dp[1] = score[1];
    int res = score[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(score[i], dp[i - 1] + score[i]);
        res = max(dp[i], res);
    }
    cout << res;
}