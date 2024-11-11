#include <bits/stdc++.h>

using namespace std;
int n;

void printStar(int cur, int y, int x)
{
    if (cur == 3)
    {
        if (y % 3 == 1 && x % 3 == 1)
            cout << ' ';
        else
            cout << '*';
        return;
    }
    if (y % 3 == 1 && x % 3 == 1)
        printStar(cur / 3, y, x);
    else
        printStar(cur / 3, y / 3, x / 3);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printStar(n, i, j);
        cout << '\n';
    }
}