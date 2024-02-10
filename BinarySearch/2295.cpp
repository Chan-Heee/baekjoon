#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;
    vector<int> sum;
    int tmp;
    int MAX = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum.push_back(v[i] + v[j]);

    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (binary_search(sum.begin(), sum.end(), abs(v[i] - v[j])))
            {
                if (v[i] > v[j])
                    MAX = max(MAX, v[j] + *lower_bound(sum.begin(), sum.end(), abs(v[i] - v[j])));
                else
                    MAX = max(MAX, v[i] + *lower_bound(sum.begin(), sum.end(), abs(v[i] - v[j])));
            }
        }
    cout << MAX;
}