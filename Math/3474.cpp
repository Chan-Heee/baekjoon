#include <bits/stdc++.h>

using namespace std;

int n, t;
int main()
{
    cin >> t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (t--)
    {
        cin >> n;
        int cnt2 = 0;
        int cnt5 = 0;

        int d = 2;
        while (n / d != 0)
        {
            cnt2 += (n / d);
            d *= 2;
        }
        d = 5;
        while (n / d != 0)
        {
            cnt5 += (n / d);
            d *= 5;
        }
        cout << min(cnt2, cnt5) << '\n';
    }
}