#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    int score[100001];
    vector<pair<int, int>> v;
    int dp[100001] = {
        0,
    };
    int start, fin;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
        dp[i] = dp[i - 1] + score[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> start >> fin;
        v.push_back(make_pair(start, fin));
    }
    for (int i = 0; i < m; i++)
    {
        cout << (dp[v[i].second] - dp[v[i].first - 1]) << '\n';
    }
}