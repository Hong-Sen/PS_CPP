#include <iostream>
#include <queue>
using namespace std;

int m,n,cnt;
int tomato[1002][1002];
queue<pair<int, int>> q;  //(y,x)
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool isInside(int y, int x){
    if(x>=0 && x<m && y>=0 && y<n) return true;
    else    return false;
}

void bfs(){
    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(isInside(ny, nx) && tomato[ny][nx]==0){
                tomato[ny][nx] = tomato[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
}

int main(){
    cin>>m>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tomato[i][j];
            if(tomato[i][j] == 1)   q.push({i,j});
        }
    }
    bfs();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tomato[i][j] == 0){
                cout<<"-1";
                return 0;
            }
            if(cnt < tomato[i][j])  cnt = tomato[i][j];
        }
    }
    cout<<cnt-1;
    
}
