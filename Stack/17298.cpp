#include <bits/stdc++.h>

using namespace std;

int n, tmp;
stack<pair<int, int>> stk;
map<int, int> m;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        if (stk.empty() || tmp <= stk.top().second)
            stk.push({i, tmp});
        else if (stk.size() && tmp > stk.top().second)
        {
            while (stk.size() && tmp > stk.top().second)
            {
                m[stk.top().first] = tmp;
                stk.pop();
            }
            stk.push({i, tmp});
        }
    }
    int t = stk.top().second;
    m[stk.top().first] = -1;
    stk.pop();
    while (stk.size())
    {
        if (t > stk.top().second)
            m[stk.top().first] = t;
        else
            m[stk.top().first] = -1;
        stk.pop();
    }
    for (pair<int, int> p : m)
        cout << p.second << ' ';
}