#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int m;
    int i = 0;
    int t;
    int mod, div;
    int tmp[10] = {0};

    cin >> m;

    div = m / 10;
    mod = m % 10;
    tmp[0] = mod;
    while (div != 0)
    {
        mod = div % 10;
        tmp[++i] = mod;
        div = div / 10;
    }
    for (int j = 0; j < i; j++)
        for (int k = j + 1; k <= i; k++)
            if (tmp[k] > tmp[j])
                swap(tmp[k], tmp[j]);

    for (int z = 0; z <= i; z++)
        cout << tmp[z];
}
