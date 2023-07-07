#include <iostream>
#include <algorithm>

using namespace std;
// dp로 최소값을 구하는 함수
int ft_find_min(int n)
{
    // 문제에서 최대 10^6까지의 수가 입력되므로 범위 맞게 배열 생성
    int dp[1000000];
    // 입력값이 2부터 이므로 dp[1]값만 0으로 설정하여도 초기값 설정이 끝난다.
    dp[1] = 0;
    // 2부터 시작하여 n까지 dp로 1로 만드는 연산횟수의 최소값을 구한다.
    for (int i = 2; i <= n; i++)
    {
        // 최소값 비교를 위한 임시 변수로 i에 따라 각 for문에서 최대값으로 초기화한다.
        int tmp1 = 1000000;
        int tmp2 = 1000000;
        int tmp3 = 1000000;
        // 3으로 나누어지게 되면 tmp1, 2로 나누어지게 되면 tmp2, 그리고 tmp3은 항상 값을 갱신한다.
        if (i % 3 == 0)
            tmp1 = dp[i / 3] + 1;
        if (i % 2 == 0)
            tmp2 = dp[i / 2] + 1;
        tmp3 = dp[i - 1] + 1;
        // 위 셋중 최소값을 찾아 dp[i]에 대입한다.
        dp[i] = min({tmp1, tmp2, tmp3});
    }
    // 최종적으로 dp[n]값 리턴한다.
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << ft_find_min(n);
}