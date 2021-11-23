#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int map[9][9];
int tmp[9][9];
int wall;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int result;

bool isInside(int row, int col){
    if(row>=0 && row<n && col>=0 && col<m) return true;
    return false;
}

void copyMap(int (*a)[9], int(*b)[9]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a[i][j] = b[i][j];
        }
    }
}

void infection(){
    int spreadVirus[9][9];
    queue<pair<int, int>> q;
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            spreadVirus[i][j] = tmp[i][j];
            if(tmp[i][j] == 2)  q.push({i,j});
        }
    }
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nr = cr + dy[i];
            int nc = cc + dx[i];
            if(isInside(nr, nc) && spreadVirus[nr][nc] == 0){
                q.push({nr, nc});
                spreadVirus[nr][nc] = 2;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(spreadVirus[i][j] == 0)  cnt++;
        }
    }
    result = max(result,cnt);
}

void makeWall(int cnt){
    if(cnt == 3){
        infection();
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp[i][j] == 0){
                tmp[i][j] = 1;
                makeWall(cnt+1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j] == 1) wall++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0){
                copyMap(tmp, map);
                tmp[i][j] = 1;
                makeWall(1);
                tmp[i][j] = 0;
            }
        }
    }
    cout<<result;

}
