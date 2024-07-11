#include <bits/stdc++.h>

using namespace std;
int n;
string s;
string ret;
vector<string> v;

void go()
{
    while (true)
    {
        if (ret.size() && ret.front() == '0')
            ret.erase(ret.begin());
        else
            break;
    }
    if (!ret.size())
        ret = "0";
    v.push_back(ret);
    ret.clear();
}

bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}
int main()
{

    cin >> n;
    while (n--)
    {
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            int k = s[i];
            if (k <= '9' && k >= '0')
                ret += (char)k;
            else if (ret.size())
                go();
        }
        if (ret.size())
            go();
    }
    sort(v.begin(), v.end(), cmp);
    for (string a : v)
        cout << a << '\n';
}