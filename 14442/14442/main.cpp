#include <iostream>
#include <queue>
using namespace std;

int n,m,k;
int map[1001][1001];
int visited[1001][1001][11];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool isInside(int row, int col){
    if(row>=0 && row<n && col>=0 && col<m)  return true;
    return false;
}

int bfs(){
    queue<pair<pair<int, int>, int>> q; // {{row,col},wall}
    q.push({{0,0},0});
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int wall = q.front().second;
        q.pop();
        if(cr == n-1 && cc == m-1)  return visited[cr][cc][wall];
        for(int i=0; i<4; i++){
            int nr = cr + dy[i];
            int nc = cc + dx[i];
            if(!isInside(nr, nc) || visited[nr][nc][wall] != 0)   continue;
            if(map[nr][nc] == 0){
                visited[nr][nc][wall] = visited[cr][cc][wall] + 1;
                q.push({{nr,nc},wall});
            }
            if(map[nr][nc] == 1 && wall < k){
                visited[nr][nc][wall+1] = visited[cr][cc][wall] + 1;
                q.push({{nr,nc},wall+1});
            }
        }
    }
    return -1;
}

int main(){
    cin>>n>>m>>k;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j] - '0';
        }
    }
    cout<<bfs()<<"\n";
}
