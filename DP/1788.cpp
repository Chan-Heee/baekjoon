#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> pl;
vector<int> mi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    pl.push_back(0);
    pl.push_back(1);
    mi.push_back(0);
    mi.push_back(1);

    if (n > 0)
    {
        cout << 1 << '\n';
        for (int i = 2; i <= n; i++)
        {
            pl[i] = (pl[i - 1] + pl[i - 2]) % 1000000000;
            pl.push_back(pl[i]);
        }
        cout << pl[n];
    }
    else if (n < 0)
    {
        for (int i = 2; i <= abs(n); i++)
        {
            mi[i] = (mi[i - 2] - mi[i - 1]) % 1000000000;
            mi.push_back(mi[i]);
        }
        mi[abs(n)] < 0 ? cout << -1 << '\n' : cout << 1 << '\n';
        cout << abs(mi[abs(n)]);
    }
    else
    {
        cout << 0 << '\n';
        cout << 0;
    }

    return 0;
}