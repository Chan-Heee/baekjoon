#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> result;

int main()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        result.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (int i = 0; i < n; i++)
    {
        cout << lower_bound(arr.begin(), arr.end(), result[i]) - arr.begin() << " ";
    }
}