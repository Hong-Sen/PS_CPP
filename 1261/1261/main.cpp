#include <iostream>
using namespace std;

int N,M;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char map[101][101];
bool isVisited[101][101];
int dp[101][101];

void dfs(int r, int c, int cnt) {
    if(dp[r][c] > cnt) {
        dp[r][c] = cnt;
    }
    else return;
        
    for(int i=0; i<4; i++) {
        int nr = r + dy[i];
        int nc = c + dx[i];
        if(nr >= 0 && nr < N && nc >= 0 && nc < M && !isVisited[nr][nc]) {
            isVisited[nr][nc] = true;
            if(map[nr][nc] == '0')  dfs(nr, nc, cnt);
            else dfs(nr, nc, cnt+1);
            isVisited[nr][nc] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    cin>>M>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            dp[i][j] = 10002;
        }
    }
    isVisited[0][0] = true;
    dfs(0, 0, 0);
    cout<<dp[N-1][M-1];
}
