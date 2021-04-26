#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int visited[101][101];
int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int x,int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = 1;
    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        if(curX == n-1 && curY == m-1)  break;
        for(int i=0; i<4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && map[nx][ny]==1 && visited[nx][ny]==0 ){
                visited[nx][ny] = visited[curX][curY] + 1;
                q.push({nx,ny});
            }
        }
    }
}


int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++)
            map[i][j] = (int)s.at(j) - 48;
    }
    bfs(0, 0);
    cout<<visited[n-1][m-1];
}
