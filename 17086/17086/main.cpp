#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int map[51][51];
int visited[51][51];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
int result;

struct shark{
    int x,y,cnt;
};

queue<shark> q;

bool isInside(int x, int y){
    if(x>=0 && y>=0 && x<m && y<n)  return true;
    else    return false;
}

void bfs(){
    int cnt = 100;
    while (!q.empty()) {
        int curX = q.front().x;
        int curY = q.front().y;
        int curCnt = q.front().cnt;
        q.pop();
        for(int i=0; i<8; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(isInside(nextX, nextY) && visited[nextY][nextX]>curCnt+1){
                visited[nextY][nextX] = curCnt+1;
                q.push({nextX, nextY,curCnt+1});
                result = max(result,curCnt+1);
            }
        }
}
    cout<<result;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = 1000;
            int x;
            cin>>x;
            if(x == 1){
                q.push({j,i,0});
                visited[i][j] = 0;
            }
            map[i][j] = x;
        }
    }
    bfs();
}
