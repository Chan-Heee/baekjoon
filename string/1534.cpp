#include <bits/stdc++.h>

using namespace std;
string s;
string f;
int ans, pos;
int main()
{
    getline(cin, s);
    getline(cin, f);

    while ((pos = s.find(f, pos)) != string::npos)
    {
        ans++;
        pos += f.size();
    }
    cout << ans;
}