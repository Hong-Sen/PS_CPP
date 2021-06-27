#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,k;
bool trash[101][101];
bool visited[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int, int>> q;
int result;

bool isInside(int y, int x){
    if(y>0 && y<=n && x>0 && x<=m)  return true;
    else    return false;
}

int bfs(int y, int x){
    int cnt = 1;
    visited[y][x] = true;
    q.push({y,x});
    
    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if(isInside(nextY, nextX) && trash[nextY][nextX] == true && !visited[nextY][nextX]){
                visited[nextY][nextX] = true;
                cnt++;
                q.push({nextY,nextX});
            }
        }
    }
    return cnt;
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<k; i++){
        int y,x;
        cin>>y>>x;
        trash[y][x] = true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(trash[i][j] && !visited[i][j]){
                result = max(result, bfs(i, j));
            }
        }
    }
    cout<<result;
}
