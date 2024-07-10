#include <bits/stdc++.h>

using namespace std;
string s;
int main()
{
    while (true)
    {
        cin >> s;
        if (s == "end")
            break;
        char pre = ' ';
        int lcnt = 0, mcnt = 0;
        bool flag1 = false, flag2 = true, flag3 = true;
        for (char c : s)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                flag1 = true;
                lcnt++;
                mcnt = 0;
            }
            else
            {
                lcnt = 0;
                mcnt++;
            }
            if (lcnt >= 3 || mcnt >= 3)
                flag2 = false;
            if (pre == c && !(c == 'e' || c == 'o'))
                flag3 = false;
            pre = c;
        }
        if (flag1 && flag2 && flag3)
            cout << "<" + s + "> is acceptable." << '\n';
        else
            cout << "<" + s + "> is not acceptable." << '\n';
    }
}
