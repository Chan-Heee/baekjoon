#include <bits/stdc++.h>

using namespace std;

int n;
string s;
long long ans = -2111111111;
vector<long long> num;
vector<char> ari;

int cal (int a, int b, char c){
    if(c == '+')
        return a+b;
    else if(c == '*')
        return a*b;
    else if (c == '-')
        return a-b;
    return 0;
}

void dfs(int here, long long sum){
    if(here == num.size() -1){
        ans = max(ans, sum);
        return;
    }
    dfs(here + 1, cal(sum,num[here+1],ari[here]));
    if(here + 2 <= num.size() - 1)
        dfs(here + 2, cal(sum,cal(num[here+1],num[here+2],ari[here+1]),ari[here]));
    
} 

int main(){

    cin >> n >> s;
    for(int i=0; i<n; i++){
        if(i % 2 ==0)
            num.push_back((s[i]-'0'));
        else
            ari.push_back(s[i]);
    }
    dfs(0,(s[0] - '0'));
    cout << ans;
    return 0;
}
