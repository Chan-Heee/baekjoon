#include <bits/stdc++.h>

using namespace std;

int n, tmp;
vector<int> arr;
vector<int> ret[14];
void go(int start, int end, int level)
{
    int mid = (start + end) / 2;
    ret[level].push_back(arr[mid]);
    if (start == end)
        return;
    go(start, mid - 1, level + 1);
    go(mid + 1, end, level + 1);
}
int main()
{
    cin >> n;
    int end = (int)pow(2, n) - 1;
    for (int i = 0; i < end; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    go(0, end - 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ret[i].size(); j++)
            cout << ret[i][j] << ' ';
        cout << '\n';
    }
}