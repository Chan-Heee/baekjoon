#include <bits/stdc++.h>

using namespace std;

int n, ans;
string s;

int main()
{
    cin >> n;
    while (n--)
    {

        stack<char> t;
        cin >> s;
        for (char k : s)
        {
            if (!t.empty() && t.top() == k)
                t.pop();
            else
                t.push(k);
        }
        if (t.empty())
            ans++;
    }
    cout << ans;
}