#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> v = {"dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z="};
    string str;
    string sub;
    int i = 0;
    int flag = 0;
    int count = 0;
    cin >> str;

    while (str[i])
    {
        sub = str.substr(i, 3);
        if (sub == v[0])
        {
            i = i + 3;
            flag = 1;
        }
        else
        {
            sub = str.substr(i, 2);
            for (int j = 1; j < 8; j++)
            {
                if (sub == v[j])
                {
                    i = i + 2;
                    flag = 1;
                    break;
                }
            }
        }
        count++;
        if (flag != 1)
            i++;
        flag = 0;
    }
    cout << count;
}
