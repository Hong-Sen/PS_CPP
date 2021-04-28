#include <iostream>
#include <queue>
using namespace std;

int n,m;
int map[1001][1001];
bool visited[1001][1001][2];
queue<pair<pair<int, int>, pair<int, int>>> q;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool flag = true;

bool isInside(int y, int x){
    if(x>=0 && x<n && y>=0 && y<m)  return true;
    else    return false;
}

int bfs(){
    q.push({{0,0},{0,1}});
    visited[0][0][0] = true;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        
        if(x == n-1 && y == m-1)    return cnt;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isInside(ny, nx)){
                if(map[nx][ny] == 1 && z == 0){
                    visited[nx][ny][z+1] = true;
                    q.push({{nx,ny},{z+1,cnt+1}});
                }
                else if(map[nx][ny] == 0 && !visited[nx][ny][z]){
                    visited[nx][ny][z] = true;
                    q.push({{nx,ny},{z,cnt+1}});
                }
            }
        }
    }
    return -1;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            map[i][j] = (int)(s.at(j)) - 48;

        }
    }
    cout<<bfs();
}
