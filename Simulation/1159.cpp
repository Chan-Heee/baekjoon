#include <bits/stdc++.h>

using namespace std;
int n;
int cnt[26];
vector<char> ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        cnt[tmp[0] - 'a']++;
        if (cnt[tmp[0] - 'a'] == 5)
            ans.push_back((char)tmp[0]);
    }
    sort(ans.begin(), ans.end());
    if (ans.empty())
        cout << "PREDAJA";
    else
    {
        for (char n : ans)
            cout << n;
    }
}