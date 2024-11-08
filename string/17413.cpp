#include <bits/stdc++.h>

using namespace std;

string s;
string ans;
int flag = 0;
stack<char> stk;
int main()
{
    getline(cin, s);
    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i] == '<')
        {
            if (!stk.empty())
            {
                while (!stk.empty())
                {
                    ans += stk.top();
                    stk.pop();
                }
            }
            flag = 1;
            ans += s[i];
            continue;
        }
        else if (s[i] == '>')
        {
            flag = 0;
            ans += s[i];
            continue;
        }
        if (flag)
            ans += s[i];
        else
        {
            if (s[i] == ' ' || s[i] == '\0')
            {
                while (!stk.empty())
                {
                    ans += stk.top();
                    stk.pop();
                }
                if (s[i] != '\0')
                    ans += s[i];
            }
            else
            {
                stk.push(s[i]);
            }
        }
    }
    cout << ans;
}