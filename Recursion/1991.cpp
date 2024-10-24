#include <bits/stdc++.h>

using namespace std;

int n;
char t, t_l, t_r;
struct Node
{
    int value;
    int left = -1;
    int right = -1;
};
vector<Node> nodes;

void pre_order_print(int cur)
{
    if (cur == -1)
        return;
    cout << (char)(cur + 'A');
    pre_order_print(nodes[cur].left);
    pre_order_print(nodes[cur].right);
}
void post_order_print(int cur)
{
    if (cur == -1)
        return;
    post_order_print(nodes[cur].left);
    post_order_print(nodes[cur].right);
    cout << (char)(cur + 'A');
}
void in_order_print(int cur)
{
    if (cur == -1)
        return;
    in_order_print(nodes[cur].left);
    cout << (char)(cur + 'A');
    in_order_print(nodes[cur].right);
}

int main()
{
    cin >> n;
    nodes.resize(n);
    for (int i = 0; i < n; i++)
    {
        Node tmp;
        cin >> t >> t_l >> t_r;
        tmp.value = t - 'A';
        if (t_l != '.')
            tmp.left = t_l - 'A';
        if (t_r != '.')
            tmp.right = t_r - 'A';
        nodes[tmp.value] = tmp;
    }
    pre_order_print(0);
    cout << '\n';
    in_order_print(0);
    cout << '\n';
    post_order_print(0);
}
