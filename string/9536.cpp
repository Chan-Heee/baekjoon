#include <bits/stdc++.h>

using namespace std;
int t;
string in;
int main()
{
    cin >> t;
    cin.ignore();
    while (t--)
    {
        map<string, int> m;
        string all;
        vector<string> v;
        getline(cin, all);
        stringstream ss(all);
        string tmp;
        while (ss >> tmp)
            v.push_back(tmp);
        while (1)
        {
            getline(cin, tmp);
            if (tmp == "what does the fox say?")
                break;
            stringstream ss2(tmp);
            string discard1, discard2, thing;
            ss2 >> discard1 >> discard2 >> thing;
            m[thing]++;
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (m[v[i]] == 0)
                cout << v[i] << ' ';
        }
        cout << '\n';
    }
}