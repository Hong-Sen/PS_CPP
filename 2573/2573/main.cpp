#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N,M;
int map[301][301];
int tmpMap[301][301];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool visitedMap[301][301];

bool isInside(int r, int c){
    return r>=0 && r<N && c>=0 && c<M;
}

void dfs(int row, int col){
    for(int i=0; i<4; i++){
        int nr = row + dy[i];
        int nc = col + dx[i];
        if(isInside(nr, nc) && map[nr][nc] != 0 && !visitedMap[nr][nc]){
            visitedMap[nr][nc] = true;
            dfs(nr, nc);
        }
    }
}

int getIceAmount(){
    int cnt = 0;
    memset(visitedMap, false, sizeof(visitedMap));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] != 0 && !visitedMap[i][j]){
                cnt++;
                dfs(i, j);
            }
        }
    }
    return cnt;
}

void melt(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tmpMap[i][j] = map[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tmpMap[i][j] != 0){
                int cnt = 0;
                for(int k=0; k<4; k++){
                    int nr = i + dy[k];
                    int nc = j + dx[k];
                    if(tmpMap[nr][nc] == 0) cnt++;
                }
                map[i][j] = max(map[i][j] - cnt, 0);
            }
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(i==0 || i==N-1 || j==0 || j==M-1) map[i][j] = 0;
        }
    }
    int cnt = 0;
    while (1) {
        if(getIceAmount() > 1){
            cout<<cnt;
            break;
        }
        else if(getIceAmount() == 0){
            cout<<"0";
            break;
        }
        cnt++;
        melt();
    }
}
