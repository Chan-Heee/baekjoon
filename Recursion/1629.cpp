#include <bits/stdc++.h>

using namespace std;
long long a, b, c;

long long foo(long long a, long long b, long long c)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % c;

    if (b % 2 == 0)
        return (foo(a, b / 2, c) * foo(a, b / 2, c)) % c;
    else
        return (foo(a, b / 2, c) * foo(a, (b / 2) + 1, c)) % c;
}

int main()
{
    cin >> a >> b >> c;
    cout << foo(a, b, c);
}