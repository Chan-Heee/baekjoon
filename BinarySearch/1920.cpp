#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> target;

int main()
{
    int in;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        arr.push_back(in);
    }
    sort(arr.begin(), arr.end());
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> in;
        target.push_back(in);
    }
    for (int i = 0; i < m; i++)
    {
        int goal = target[i];
        int st = 0;
        int en = arr.size() - 1;
        int mid;

        while (true)
        {
            mid = (st + en) / 2;
            if (en < st)
            {
                cout << '0' << '\n';
                break;
            }
            if (arr[mid] == goal)
            {
                cout << '1' << '\n';
                break;
            }
            else if (arr[mid] > goal)
                en = mid - 1;
            else if (arr[mid] < goal)
                st = mid + 1;
        }
    }
}