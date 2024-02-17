#include <iostream>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0, tmp; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    int start = 0;
    int end = arr.size() - 1;
    int MIN = 2147480000;
    int var1;
    int var2;

    while (start < end)
    {
        int sum = arr[start] + arr[end];
        if (abs(sum) < MIN)
        {
            MIN = abs(sum);
            var1 = arr[start];
            var2 = arr[end];
        }
        if (sum == 0)
            break;
        else if (sum > 0)
            end--;
        else
            start++;
    }
    cout << var1 << " " << var2;
}