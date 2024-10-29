#include <bits/stdc++.h>

using namespace std;
int a, idx;

int main()
{
    // 해당 idx 비트 끄기
    a = 10; // 1010(2) = 10
    idx = 1;
    a &= ~(1 << idx);
    cout << a << '\n'; // 1000(2) = 8

    // 해당 idx 비트 켜기
    a = 10; // 1010(2) = 10
    idx = 2;
    a |= 1 << idx;
    cout << a << '\n'; // 1110(2) = 14

    // 해당 idx 비트 반전
    a = 10;
    idx = 3;
    a ^= (1 << idx);
    cout << a << '\n'; // 0010(2) = 2

    // 최하위 켜져있는 비트 idx 찾기
    a = 18; // 10010(2) = 18
    idx = (a & -a) / 2;
    cout << idx << '\n';

    // idx번째가 켜져있는지 확인
    a = 18; // 10010(2) = 18
    idx = 4;
    if (a & (1 << idx))
        cout << true << '\n';
}