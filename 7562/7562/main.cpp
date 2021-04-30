#include <iostream>
#include <queue>
using namespace std;

int t,n;
int chess[300][300];
bool visited[300][300];
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

int bfs(int startX, int startY, int endX, int endY){
    queue<pair<int, int>> q;
    q.push({startX,startY});
    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        visited[curX][curY] = true;
        q.pop();
        if(curX == endX && curY == endY)    return chess[endX][endY];
        for(int i=0; i<8; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny] = true;
                chess[nx][ny] = chess[curX][curY] + 1;
            }
        }
    }
    return -1;
}

void resetChess(int k){
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            chess[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main(){
    cin>>t;
    int startX,startY,endX,endY;
    for(int i=0; i<t; i++){
        cin>>n;
        cin>>startX>>startY>>endX>>endY;
        resetChess(n);
        cout<<bfs(startX, startY, endX, endY)<<"\n";
    }
}
