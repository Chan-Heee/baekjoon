#include <iostream>
#include <deque>

using namespace std;

int n;
int w;
int l;
int truck[1002];
deque<int> bridge;
int cur_weight;
int ans;

int main()
{
    cin >> n >> w >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> truck[i];
    }
    for (int i = 0; i < n; i++)
    {

        while (cur_weight + truck[i] > l)
        {
            {
                bridge.push_back(0);
                ans++;
                if (bridge.size() == (w))
                {
                    cur_weight -= bridge.front();
                    bridge.pop_front();
                }
            }
        }

        cur_weight += truck[i];
        bridge.push_back(truck[i]);
        ans++;
        if (bridge.size() == (w))
        {
            cur_weight -= bridge.front();
            bridge.pop_front();
        }
    }
    ans += w;
    cout << ans;
}