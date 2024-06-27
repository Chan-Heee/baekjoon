#include <bits/stdc++.h>

using namespace std;

int fee[4];
int t[104];
int ans;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    fee[1] = a;
    fee[2] = b;
    fee[3] = c;
    for (int i = 0; i < 3; i++)
    {
        int begin, end;
        cin >> begin >> end;
        for (int j = begin; j < end; j++)
            t[j]++;
    }

    for (int i = 1; i <= 99; i++)
        ans += fee[(t[i] % 4)] * t[i];

    cout << ans;
}