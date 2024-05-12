#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int k;
    vector<int> v;
    int cnt = 0;
    cin >> n;
    cin >> k;

    for (int i = 0, j; i < n; i++)
    {
        cin >> j;
        v.push_back(j);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cnt = cnt + k / v[i];
        k = k % v[i];
    }
    cout << cnt;
}