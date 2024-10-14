#include <bits/stdc++.h>

using namespace std;

int a,b,ok,turn = 1;
int visited[2][500004];

int main(){

    cin >> a >> b;
    if(a == b)
    {
        cout << 0;
        return 0;
    }
    queue<int> q;
    q.push(a);
    visited[0][a] = 1;
    while(!q.empty()){
        b += turn;
        if(b > 500000)
            break;
        if(visited[turn % 2][b]){
            ok = 1;
            break;
        }
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            int cur = q.front();
            q.pop();
            for(int next : {cur + 1, cur -1, cur * 2}){
                if(next <0 || next > 500000 || visited[turn % 2][next])
                    continue;
                visited[turn % 2][next] = visited[(turn + 1) % 2][cur] + 1;
                if(next == b){
                    ok = 1;
                    break;
                }
                q.push(next);
            }
            if(ok)
                break;
        }
        if(ok)
            break;
        turn ++;
    }
    if(ok) cout << turn;
    else cout << -1;
}