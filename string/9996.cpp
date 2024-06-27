#include <bits/stdc++.h>

using namespace std;

int n;
string pattern;
string s[200];

vector<string> split(string input, string delimeter)
{
    vector<string> ret;
    string token = "";
    long long pos = 0;
    while ((pos = input.find(delimeter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    ret.push_back(input);
    return ret;
}

int main()
{
    cin >> n >> pattern;
    string a = split(pattern, "*")[0];
    string b = split(pattern, "*")[1];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        int pos = s[i].find(a);
        if (pos == 0)
        {
            s[i] = s[i].substr(a.length(), s[i].length() - a.length());
            if (s[i].length() >= b.length())
            {
                s[i] = s[i].substr(s[i].length() - b.length(), b.length());
                pos = s[i].find(b);
                if (pos == 0)
                {
                    cout << "DA" << '\n';
                    continue;
                }
            }
        }
        cout << "NE" << '\n';
    }
}