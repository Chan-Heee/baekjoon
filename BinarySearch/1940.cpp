#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;
int ans;
int main()
{
    cin >> n >> m;
    for (int i = 0, tmp; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    for (int k : arr)
    {
        int goal = m - k;
        auto it = lower_bound(arr.begin(), arr.end(), goal);
        if (it != arr.end() && *it == goal)
            ans++;
    }
    cout << ans / 2;
}