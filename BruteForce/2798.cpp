#include <iostream>

using namespace std;
int card[100] = {0};

int main()
{
    int n;
    int goal;
    int max = 0;
    cin >> n >> goal;

    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
    }

    for (int i = 0; i < n - 2; i++)
    {
        int sum = card[i];
        for (int j = i + 1; j < n - 1; j++)
        {
            sum = sum + card[j];
            for (int k = j + 1; k < n; k++)
            {
                sum = sum + card[k];
                if (sum > max && sum <= goal)
                    max = sum;
                sum = sum - card[k];
            }
            sum = sum - card[j];
        }
    }
    cout << max;
}