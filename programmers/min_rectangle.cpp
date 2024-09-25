#include <bits/stdc++.h>

using namespace std;
int m_w, m_h;

int solution(vector<vector<int>> sizes)
{
    m_w = sizes[0][0];
    m_h = sizes[0][1];
    for (int i = 0; i < sizes.size(); i++)
    {
        if (m_w >= sizes[i][0] && m_h >= sizes[i][1])
            continue;

        if (max(sizes[i][1], m_w) * max(sizes[i][0], m_h) >= max(sizes[i][0], m_w) * max(sizes[i][1], m_h))
        {
            m_w = max(sizes[i][0], m_w);
            m_h = max(sizes[i][1], m_h);
        }
        else
        {
            m_w = max(sizes[i][1], m_w);
            m_h = max(sizes[i][0], m_h);
        }
    }
    return m_w * m_h;
}