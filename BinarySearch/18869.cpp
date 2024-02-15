#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
int result;
vector<vector<int>> arr;
vector<vector<int>> cp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    int tmp;
    vector<int> t;
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            v.push_back(tmp);
            t.push_back(tmp);
        }
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        for (int k = 0; k < v.size(); k++)
        {
            int index = lower_bound(t.begin(), t.end(), v[k]) - t.begin();
            v[k] = index;
        }
        arr.push_back(v);
        cp.push_back(t);
        v.clear();
        t.clear();
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (cp[i].size() != cp[j].size())
                continue;
            int flag = 1;
            for (int k = 0; k < n; k++)
            {
                if (arr[i][k] != arr[j][k])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                result++;
        }
    }
    cout << result;
}