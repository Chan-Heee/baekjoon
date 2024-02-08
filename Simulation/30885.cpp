#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    list<pair<long long int, long long int>> l;
    cin >> n;
    long long int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        l.push_back({i, tmp});
    }

    while (l.size() != 1)
    {
        list<pair<long long int, long long int>>::iterator cur = l.begin();
        while (1)
        {
            if (cur == l.end())
                break;
            if (cur == l.begin())
            {
                if ((*cur).second >= (*(next(cur))).second)
                {
                    (*cur).second = (*cur).second + (*(next(cur))).second;
                    l.erase(next(cur));
                }
            }
            else if (cur == prev(l.end()))
            {
                if ((*cur).second >= (*(prev(cur))).second)
                {
                    (*cur).second = (*cur).second + (*(prev(cur))).second;
                    l.erase(prev(cur));
                }
            }
            else
            {
                long long int tmp = (*cur).second;
                if (tmp >= (*(next(cur))).second)
                {
                    (*cur).second = (*cur).second + (*(next(cur))).second;
                    l.erase(next(cur));
                }
                if (tmp >= (*(prev(cur))).second)
                {
                    (*cur).second = (*cur).second + (*(prev(cur))).second;
                    l.erase(prev(cur));
                }
            }
            if (cur != l.end())
                cur = next(cur);
        }
    }
    cout << l.front().second << '\n';
    cout << l.front().first + 1;
}
