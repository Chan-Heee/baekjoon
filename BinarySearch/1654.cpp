#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long k, n;
    cin >> k >> n;

    long long tmp;
    vector<long long> v;

    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    long long start = 1;
    long long end = v[v.size() - 1];
    long long mid;
    long long sum = 0;
    long long result;

    while (start <= end)
    {
        mid = (start + end) / 2;
        sum = 0;

        for (int i = 0; i < v.size(); i++)
            sum = sum + (v[i] / mid);

        if (n > sum)
            end = mid - 1;
        else
        {
            result = mid;
            start = mid + 1;
        }
    }
    cout << result;
}