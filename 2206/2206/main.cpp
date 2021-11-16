#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
string s;
int map[1001][1001];
int visited[1001][1001][2];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool isInside(int row, int col){
    if(row>=0 && row<n && col>=0 && col<m)  return true;
    else return false;
}

int bfs(){
    queue<pair<pair<int, int>, int>> q; // {{row,col},wall}
    q.push({{0,0},0});
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int wall = q.front().second;
        q.pop();
        if(curR == n-1 && curC == m-1)  return visited[curR][curC][wall];
        for(int i=0; i<4; i++){
            int nextR = dy[i] + curR;
            int nextC = dx[i] + curC;
            if(!isInside(nextR, nextC) || visited[nextR][nextC][wall] != 0) continue;
            if(map[nextR][nextC] == 0){
                visited[nextR][nextC][wall] = visited[curR][curC][wall] + 1;
                q.push({{nextR,nextC},wall});
            }
            if(map[nextR][nextC] == 1 && wall == 0){
                visited[nextR][nextC][wall+1] = visited[curR][curC][wall] + 1;
                q.push({{nextR,nextC},wall+1});
            }
        }
    }
    return -1;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j] - '0';
        }
    }
    cout<<bfs()<<"\n";
}
