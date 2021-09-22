#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int cheese[101][101];
bool visited[101][101];
int cheeseCnt;
int meltingTime;
int lastCnt;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
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
            if(!visited[ny][nx] && isInside(nx, ny)){
                visited[ny][nx] = true;
                if(cheese[ny][nx] == 0){
                    q.push({nx,ny});
                }
                else{
                    cheese[ny][nx] = 0;
                    cheeseCnt--;
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>cheese[i][j];
            if(cheese[i][j] == 1)   cheeseCnt++;
        }
    }

    while (1) {
        if(cheeseCnt == 0){
            cout<<meltingTime<<"\n"<<lastCnt<<"\n";
            return 0;
        }
        else{
            meltingTime++;
            lastCnt = cheeseCnt;
            memset(visited, false, sizeof(visited));
            q.push({0,0});
            bfs();
        }
    }
}
