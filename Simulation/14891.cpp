#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    string in;
    vector<vector<int>> status(5, vector<int>(8, 0));
    vector<vector<int>> result(5, vector<int>(8, 0));
    int k;
    for (int i = 0; i < 4; i++)
    {
        cin >> in;
        for (int j = 0; j < 8; j++)
        {
            status[i + 1][j] = in[j] - '0';
            result[i + 1][j] = in[j] - '0';
        }
    }
    cin >> k;
    while (k--)
    {
        int num, dir;
        cin >> num >> dir;
        int cur_dir = dir;
        if (dir == 1)
        {
            status[num].insert(status[num].begin(), status[num].at(7));
            status[num].erase(status[num].end() - 1);
        }
        else
        {
            status[num].insert(status[num].end(), status[num].at(0));
            status[num].erase(status[num].begin());
        }
        for (int i = num - 1; i >= 1; i--)
        {
            if (result[i][2] == result[i + 1][6])
                break;
            cur_dir = cur_dir * -1;
            if (cur_dir == 1)
            {
                status[i].insert(status[i].begin(), status[i].at(7));
                status[i].erase(status[i].end() - 1);
            }
            else
            {
                status[i].insert(status[i].end(), status[i].at(0));
                status[i].erase(status[i].begin());
            }
        }
        cur_dir = dir;
        for (int i = num + 1; i <= 4; i++)
        {
            if (result[i][6] == result[i - 1][2])
                break;
            cur_dir = cur_dir * -1;
            if (cur_dir == 1)
            {
                status[i].insert(status[i].begin(), status[i].at(7));
                status[i].erase(status[i].end() - 1);
            }
            else
            {
                status[i].insert(status[i].end(), status[i].at(0));
                status[i].erase(status[i].begin());
            }
        }
        for (int i = 1; i <= 4; i++)
            for (int j = 0; j < 8; j++)
            {
                result[i][j] = status[i][j];
            }
    }
    int sum = 0;
    for (int i = 1; i <= 4; i++)
    {
        sum = sum + ((status[i][0] == 1) ? pow(2, i - 1) : 0);
    }
    cout << sum;
}
