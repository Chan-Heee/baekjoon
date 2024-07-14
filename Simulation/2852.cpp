#include <bits/stdc++.h>

using namespace std;

int n, t, s1, s2, ret1, ret2;
int score1[2884];
int score2[2884];
string s;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> t >> s;
        (t == 1) ? score1[stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2))]++ : score2[(stoi(s.substr(0, 2)) * 60) + stoi(s.substr(3, 2))]++;
    }
    for (int i = 0; i < 2880; i++)
    {
        s1 += score1[i];
        s2 += score2[i];
        if (s1 > s2)
            ret1++;
        else if (s2 > s1)
            ret2++;
    }

    printf("%02d:%02d\n", ret1 / 60, ret1 % 60);
    printf("%02d:%02d", ret2 / 60, ret2 % 60);
}