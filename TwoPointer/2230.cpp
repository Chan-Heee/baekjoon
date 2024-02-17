#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    if (m == 0)
    {
        cout << 0;
        return 0;
    }

    vector<int> v;

    for (int i = 0, tmp; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int diff;
    int MIN = 2147480000;
    int small = 0;
    int big = 0;

    while (big != n)
    {
        diff = v[big] - v[small];
        if (diff >= m && diff < MIN)
            MIN = diff;
        if (MIN == m)
        {
            cout << MIN;
            return 0;
        }
        else if (diff > m)
        {
            small++;
        }
        else
        {
            big++;
        }
    }
    cout << MIN;
}