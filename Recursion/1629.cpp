#include <iostream>

using namespace std;

long long recursion(long long a, long long b, long long c)
{
    if (b == 1)
        return a % c;
    long long tmp = recursion(a, b / 2, c);
    long long result = (tmp * tmp) % c;
    if (b % 2 == 1)
        result = result * a % c;
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << recursion(a, b, c);
}