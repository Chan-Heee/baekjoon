#include <bits/stdc++.h>

using namespace std;

int n, cnt, ret;
int main()
{
    cin >> n;
    while (cnt != n)
    {
        string s = to_string(++ret);
        int cnt6 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '6')
            {
                cnt6++;
                if (cnt6 >= 3)
                {
                    cnt++;
                    break;
                }
            }
            else
                cnt6 = 0;
        }
    }
    cout << ret;
}