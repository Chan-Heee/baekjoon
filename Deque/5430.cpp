#include <bits/stdc++.h>

using namespace std;

int t, n;
string comm, num;
int main()
{
    cin >> t;
    while (t--)
    {
        deque<int> d;
        cin >> comm;
        cin >> n;
        cin >> num;
        for (int i = 0; i < num.size(); i++)
        {
            string tmp;
            while (num[i] >= '0' && num[i] <= '9')
                tmp.push_back(num[i++]);
            if (tmp.size())
                d.push_back(stoi(tmp));
        }
        bool isReverse = false;
        bool isError = false;
        for (char c : comm)
        {
            if (c == 'R')
                isReverse = !isReverse;
            else if (c == 'D')
            {
                if (!d.size())
                {
                    cout << "error" << '\n';
                    isError = true;
                    break;
                }
                (isReverse) ? d.pop_back() : d.pop_front();
            }
        }
        if (!isError)
        {
            if (!d.size())
                cout << "[]" << '\n';
            else if (isReverse)
            {
                cout << '[';
                for (int i = d.size() - 1; i >= 0; i--)
                {
                    if (i == 0)
                        cout << d[i] << ']' << '\n';
                    else
                        cout << d[i] << ',';
                }
            }
            else
            {
                cout << '[';
                for (int i = 0; i < d.size(); i++)
                {
                    if (i == d.size() - 1)
                        cout << d[i] << ']' << '\n';
                    else
                        cout << d[i] << ',';
                }
            }
        }
    }
}
