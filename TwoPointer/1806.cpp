#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    vector<int> arr;
    cin >> n >> s;
    int tmp;
    int diff = 2147483647;
    arr.push_back(0);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> tmp;
        tmp = tmp + arr[i - 1];
        arr.push_back(tmp);
    }
    if (arr[n] < s)
    {
        cout << 0;
        return 0;
    }

    int start = 0;
    int end = 1;
    int sum;
    int t_diff;
    while (end < n + 1)
    {
        sum = arr[end] - arr[start];
        t_diff = end - start;
        if (sum >= s && t_diff < diff)
            diff = t_diff;
        if (sum > s)
        {
            start++;
        }
        else
        {
            end++;
        }
    }
    cout << diff;
}