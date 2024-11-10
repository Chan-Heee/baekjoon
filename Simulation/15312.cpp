#include <bits/stdc++.h>

using namespace std;

int alpha[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int main()
{
    string a, b;
    cin >> a >> b;
    int arr[4004];
    for (int i = 0, d = 0; i < a.size(); i++, d += 2)
        arr[d] = alpha[a[i] - 'A'];
    for (int i = 0, d = 1; i < b.size(); i++, d += 2)
        arr[d] = alpha[b[i] - 'A'];

    int cur = a.size() * 2 - 1;
    while (cur >= 2)
    {
        for (int i = 0; i < cur; i++)
            arr[i] = (arr[i] + arr[i + 1]) % 10;
        cur--;
    }
    cout << arr[0] << arr[1];
}