#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[1000000];
    int in[1000];
    for (int i = 0; i < n; i++)
        cin >> in[i];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 10; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[in[i]] << "\n";
    }
}