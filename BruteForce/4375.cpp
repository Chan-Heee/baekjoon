#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    while (getline(cin, s))
    {
        int n = atoi(s.c_str());
        long long tmp = 1;
        int ans = 1;
        while ((tmp % (long long)n) != 0)
        {
            tmp = (tmp * 10 + 1) % n;
            ans++;
        }
        cout << ans << '\n';
    }
}