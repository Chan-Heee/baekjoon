#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];

int main()
{
    string a;
    string b;
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    cout << dp[a.size()][b.size()];
}