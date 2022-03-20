#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[101][101];
bool visited[101][101];
priority_queue<int> pq;
int n,cnt,maxH;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool isValid(int a, int b){
    return a>=0 && a<n && b>=0 && b<n;
}

void dfs(int a, int b, int h){
    visited[a][b] = true;
    for(int i=0; i<4; i++){
        int ny = a + dx[i];
        int nx = b + dy[i];
        if(isValid(ny, nx) && map[ny][nx] > h && !visited[ny][nx] ){
            dfs(ny, nx, h);
        }
    }
}

void SafeArea(int n){
    for(int h=1; h<=maxH; h++){
        cnt = 0;
        memset(visited, false, sizeof(visited));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                if(map[i][j] > h && !visited[i][j]){
                    cnt++;
                    dfs(i, j, h);
                }
        }
        pq.push(cnt);
    }
    pq.push(1);
    cout<<pq.top();
}

int main(){
    cin>>n;
    for(int i=0; i<n ;i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
            maxH = max(maxH, map[i][j]);
        }
    }
    
    SafeArea(n);
    
    return 0;
}

