#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n,m;
bool arr[101][101];
int visited[101][101];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

bool isInside(int a, int b){
    return (a>=0 && a<n) && (b>=0 && b<m);
}

int bfs(int x, int y){
    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x, y));
    
    while (!q.empty()) {
        int curX = q.front().second;
        int curY = q.front().first;
        q.pop();
        
        if((curY == n-1) && (curX == m-1))  break;
        
        for(int i=0; i<4; i++){
            int nextX = curX + dir[i][1];
            int nextY = curY + dir[i][0];
            
            if(isInside(nextY, nextX) && visited[nextY][nextX]==0 && arr[nextY][nextX]){
                visited[nextY][nextX] = visited[curY][curX] + 1;
                q.push(pair<int, int>(nextY, nextX));
            }
        }
        
        
    }
   
    return visited[n-1][m-1];
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            scanf("%1d", &x);
            if(x==1)    arr[i][j] = true;
        }
    }
    cout<<bfs(0, 0)<<"\n";
    
}
