#include <iostream>
#include <algorithm>

using namespace std;

int t;
int w;
int score[1001];
int dp[1001][2][31];
int result;

int main()
{
    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> score[i];
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j == 0)
                dp[i][0][0] = dp[i - 1][0][0] + (score[i] == 1);
            else
            {
                dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j - 1]) + (score[i] == 1);

                dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][0][j - 1]) + (score[i] == 2);
            }
        }
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            result = max({dp[i][0][j], dp[i][1][j], result});
        }
    }
    cout << result;
}