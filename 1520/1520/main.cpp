#include <iostream>
#include <vector>
using namespace std;

int n,m;
int arr[501][501];
int dp[501][501];
int dx[4] = {-1,1,0,0};
int dy[4]= {0,0,-1,1};

bool isValid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m)  return true;
    return false;
}

int dfs(int x, int y){
    if(dp[y][x] != -1)   return dp[y][x];
    if(x == n-1 && y == m-1)    return 1;
    dp[y][x] = 0;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isValid(nx, ny) && arr[y][x] > arr[ny][nx]){
            if(dp[ny][nx] != -1) dp[y][x] += dp[ny][nx];
            else    dp[y][x] += dfs(nx, ny);
        }
    }
    return dp[y][x];
}

int main(){
    cin>>m>>n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout<<dfs(0, 0);
}
