#include <bits/stdc++.h>
using namespace std;

int r, c, k, t;
int count_r = 3, count_c = 3;
int arr[104][104];

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    cin >> r >> c >> k;
    r--; // 1-based index를 0-based로 변환
    c--;

    // 초기 배열 입력
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    if (arr[r][c] == k)
    {
        cout << 0;
        return 0;
    }

    while (t <= 100)
    {
        t++;
        if (count_r >= count_c)
        {
            // R 연산
            int new_count_c = 0;
            for (int i = 0; i < count_r; i++)
            {
                map<int, int> freq_map;
                for (int j = 0; j < count_c; j++)
                {
                    if (arr[i][j] != 0)
                        freq_map[arr[i][j]]++;
                }

                vector<pair<int, int>> freq_vec(freq_map.begin(), freq_map.end());
                sort(freq_vec.begin(), freq_vec.end(), compare);

                int idx = 0;
                for (auto p : freq_vec)
                {
                    if (idx < 100)
                    {
                        arr[i][idx++] = p.first;
                        arr[i][idx++] = p.second;
                    }
                }
                new_count_c = max(new_count_c, idx);

                // 나머지 부분 0으로 초기화
                while (idx < 100)
                {
                    arr[i][idx++] = 0;
                }
            }
            count_c = min(100, new_count_c);
        }
        else
        {
            // C 연산
            int new_count_r = 0;
            for (int j = 0; j < count_c; j++)
            {
                map<int, int> freq_map;
                for (int i = 0; i < count_r; i++)
                {
                    if (arr[i][j] != 0)
                        freq_map[arr[i][j]]++;
                }

                vector<pair<int, int>> freq_vec(freq_map.begin(), freq_map.end());
                sort(freq_vec.begin(), freq_vec.end(), compare);

                int idx = 0;
                for (auto p : freq_vec)
                {
                    if (idx < 100)
                    {
                        arr[idx++][j] = p.first;
                        arr[idx++][j] = p.second;
                    }
                }
                new_count_r = max(new_count_r, idx);

                // 나머지 부분 0으로 초기화
                while (idx < 100)
                {
                    arr[idx++][j] = 0;
                }
            }
            count_r = min(100, new_count_r);
        }

        // 종료 조건 확인
        if (arr[r][c] == k)
        {
            cout << t;
            return 0;
        }
    }

    // 100초가 지나도 찾지 못한 경우
    cout << -1;
    return 0;
}
