#include <bits/stdc++.h>

using namespace std;

int k;
char ch[10];
string s;
int visited[10];
string ansMax = "0000000000", ansMin = "9999999999";

void dfs(int cnt){
    if(cnt == k + 1){
       if(ansMax < s)
            ansMax = s;
        if(ansMin > s)
            ansMin = s;
        return;
    }
    for(int i=0; i<=9; i++){
        if(!visited[i]){
            if(cnt == 0 || (ch[cnt-1] == '>' && i < s[cnt-1] - '0') || ch[cnt-1] == '<' && i > s[cnt-1] - '0' )
            {
                visited[i] = 1;
                s.push_back(i + '0');
                dfs(cnt+1);
                visited[i] = 0;
                s.pop_back();
            }
        }
    }
}
int main(){
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> ch[i];
    }
    dfs(0);
    cout << ansMax << '\n' << ansMin;
}