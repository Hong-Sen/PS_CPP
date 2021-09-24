#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int meltingTime;
int cheeseCnt;
int cheese[101][101];
int visited[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int, int>> q;

bool isInside(int x, int y){
    if(x>=0 && y>=0 && x<m && y<n) return true;
    else return false;
}

void bfs(){
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isInside(nx, ny) && cheese[ny][nx] == 0 && visited[ny][nx] == 0){
                visited[ny][nx] = -1;
                q.push({nx,ny});
            }
            if(isInside(nx, ny) && cheese[ny][nx] == 1){
                if(visited[ny][nx] == 1){
                    cheese[ny][nx] = 0;
                    cheeseCnt--;
                    visited[ny][nx] = -1;
                }
                if(visited[ny][nx] == 0)    visited[ny][nx] = 1;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>cheese[i][j];
            if(cheese[i][j] == 1) cheeseCnt++;
        }
    }
    while (1) {
        if(cheeseCnt == 0){
            cout<<meltingTime;
            return 0;
        }
        else{
            q.push({0,0});
            memset(visited, 0, sizeof(visited));
            meltingTime++;
            bfs();
        }
    }
}
