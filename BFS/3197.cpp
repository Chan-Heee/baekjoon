#include <bits/stdc++.h>

using namespace std;

char board[1501][1501];
string s;
int r,c,flag,day,flag2;
queue<pair<int,int>> sw;
queue<pair<int,int>> wt;
int visited_sw[1501][1501];
int visited_wt[1501][1501];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


void swan_move(queue<pair<int,int>> & sw_tmp){

    while(sw.size()){
        pair<int,int> cur = sw.front();
        sw.pop();
        for(int i=0; i<4; i++){
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny<0 || nx < 0 || ny>=r || nx >= c || visited_sw[ny][nx])
                continue;
            else if(board[ny][nx] == '.')
                sw.push({ny,nx});
            else if(board[ny][nx] == 'X')
                sw_tmp.push({ny,nx});
            else if(board[ny][nx] == 'L')
            {
                flag = 1;
                break;
            }
            visited_sw[ny][nx] = 1;
        }
        if(flag)
            break;
    }
}

void ice_melt(queue<pair<int,int>> & wt_tmp){
    while(wt.size()){
        pair<int,int> cur = wt.front();
        wt.pop();
        for(int i=0; i<4; i++){
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny<0 || nx < 0 || ny>=r || nx >= c || visited_wt[ny][nx])
                continue;
            else if(board[ny][nx] == 'X')
            {
                board[ny][nx] = '.';
                wt_tmp.push({ny,nx});
            }
            else if(board[ny][nx] == '.' || board[ny][nx] == 'L')
                wt.push({ny,nx});
            visited_wt[ny][nx] = 1;
        }
    }
}
int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        cin >> s;
        for(int j=0; j<c; j++){
            board[i][j] = s[j];
            if(s[j] == 'L' && !flag2)
            {
                flag2 = 1;
                sw.push({i,j});
                visited_sw[i][j] = 1;

            }
            else if(s[j] == '.' || s[j] == 'L'){
                wt.push({i,j});
                visited_wt[i][j] = 1;
            }
        }
    }
    while(1){
        queue<pair<int,int>> sw_tmp;
        swan_move(sw_tmp);
        if(flag == 1)
            break;
        sw = sw_tmp;
        queue<pair<int,int>> wt_tmp;
        ice_melt(wt_tmp);
        wt = wt_tmp;
        day++;
    }
    cout << day;
}