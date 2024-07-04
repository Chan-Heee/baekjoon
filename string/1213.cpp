#include <bits/stdc++.h>

using namespace std;
string s;
int cnt[26];
int f;

int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        cnt[s[i] - 'A']++;
    if (s.length() % 2 == 0)
    {
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] % 2 != 0)
            {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    }
    else
    {
        int flag = 0;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] % 2 == 1)
            {
                flag++;
                f = i;
            }
        }
        if (flag != 1)
        {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }

    char ans[51];
    ans[s.length()] = '\0';
    if (s.length() % 2 == 1)
    {
        ans[s.length() / 2] = f + 'A';
        cnt[f]--;
    }
    for (int i = 0; i <= (s.length() / 2); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (cnt[j])
            {
                ans[i] = j + 'A';
                ans[s.length() - 1 - i] = j + 'A';
                cnt[j]--;
                cnt[j]--;
                break;
            }
        }
    }
    cout << ans;
}
