#include <bits/stdc++.h>

using namespace std;

string s;
int main()
{
    while (getline(cin, s))
    {
        if (s == ".")
            break;
        stack<char> stk;
        bool flag = true;
        for (char c : s)
        {
            if (c == '(' || c == '[')
                stk.push(c);
            else if (c == ')' || c == ']')
            {
                if ((!stk.size()) || (c == ')' && stk.top() != '(') || (c == ']' && stk.top() != '['))
                {
                    flag = false;
                    break;
                }
                stk.pop();
            }
        }
        (flag && !stk.size()) ? cout << "yes" : cout << "no";
        cout << '\n';
    }
}