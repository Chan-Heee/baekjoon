#include <iostream>

using namespace std;
int dp[1000][2];

int main()
{
    int n;
    int in;
    dp[0][0] = 1;
    dp[1][1] = 1;
    cin >> n;
    for (int i = 2; i <= 1000; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        cout << dp[in][0] << " " << dp[in][1];
        cout << "\n";
    }
}