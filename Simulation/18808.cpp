#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int board[41][41];

class Sticker
{
public:
    int n;
    int m;
    int arr[12][12];
};

vector<Sticker> sticker;

bool check_possible(int cur)
{
    if (sticker[cur].n > n || sticker[cur].m > m)
        return false;
    for (int i = 0; i + sticker[cur].n <= n; i++)
    {
        for (int j = 0; j + sticker[cur].m <= m; j++)
        {
            bool flag = true;
            for (int x = 0; x < sticker[cur].n; x++)
                for (int y = 0; y < sticker[cur].m; y++)
                {
                    if (board[i + x][j + y] == 1 && sticker[cur].arr[0 + x][0 + y] == 1)
                        flag = false;
                }
            if (flag)
            {
                for (int x = 0; x < sticker[cur].n; x++)
                    for (int y = 0; y < sticker[cur].m; y++)
                    {
                        if (sticker[cur].arr[0 + x][0 + y] == 1)
                            board[i + x][j + y] = 1;
                    }
                return true;
            }
        }
    }
    return false;
}

void rotate_sticker(int cur)
{
    int rotated[12][12];

    for (int i = 0; i < sticker[cur].m; i++)
    {
        for (int j = 0; j < sticker[cur].n; j++)
        {
            rotated[i][j] = sticker[cur].arr[sticker[cur].n - 1 - j][i];
        }
    }
    for (int i = 0; i < sticker[cur].m; i++)
    {
        for (int j = 0; j < sticker[cur].n; j++)
        {
            sticker[cur].arr[i][j] = rotated[i][j];
        }
    }
    int tmp = sticker[cur].n;
    sticker[cur].n = sticker[cur].m;
    sticker[cur].m = tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        Sticker s;

        cin >> s.n >> s.m;
        for (int j = 0; j < s.n; j++)
            for (int l = 0; l < s.m; l++)
                cin >> s.arr[j][l];

        sticker.push_back(s);
    }

    for (int i = 0; i < k; i++)
    {
        if (check_possible(i))
            continue;

        int cnt = 0;
        while (cnt < 3)
        {
            rotate_sticker(i);
            if (check_possible(i))
                break;
            cnt++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (board[i][j])
                ans++;
        }
    cout << ans;
}