#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    int dp[1000][1000];
    int MAX = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string in;
        cin >> in;
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = in[j] - '0';
            if (dp[i][j] == 1)
                MAX = 1;
        }
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (dp[i][j] == 1)
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                MAX = max(dp[i][j], MAX);
            }
        }
    cout << MAX * MAX;
}