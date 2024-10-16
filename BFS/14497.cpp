#include <bits/stdc++.h>

using namespace std;

int n,m,jx,jy,tx,ty;
char board[304][304];
bool visited[304][304];
int dist[304][304];
string s;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    
    cin >> n >> m >> jy >> jx >> ty >> tx;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            board[i][j] = s[j];
        }
    }

    queue<pair<int,int>> q;
    q.push({jy-1,jx-1});
    visited[jy-1][jx-1] = true;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(nx>=0 && nx < m && ny >= 0 && ny < n){
                if(!visited[ny][nx]){
                    
                    if(board[cur.first][cur.second] == '0')
                        dist[ny][nx] = dist[cur.first][cur.second];
                    else
                        dist[ny][nx] = dist[cur.first][cur.second] + 1;
            
                    visited[ny][nx] = true;
                    q.push({ny,nx});
                }
                else if(board[cur.first][cur.second] == '0' && dist[ny][nx] > dist[cur.first][cur.second]){      
                     dist[ny][nx] = dist[cur.first][cur.second];
                     q.push({ny,nx});
                }
                else if(board[cur.first][cur.second] == '1' && dist[ny][nx] > dist[cur.first][cur.second] +1)
                {
                    dist[ny][nx] = dist[cur.first][cur.second] + 1;
                    q.push({ny,nx});
                }
            }
        }
    }
    cout << dist[ty-1][tx-1];
}