//
//  main.cpp
//  1987_2
//
//  Created by 홍세은 on 2022/04/02.
//

#include <iostream>
#include <vector>
using namespace std;

int R,C;
int map[21][21];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
bool visited[27];
int maxCnt;

void dfs(int r, int c, int cnt){
    maxCnt = max(cnt, maxCnt);
    for(int i=0; i<4; i++){
        int nr = r + dy[i];
        int nc = c + dx[i];
        if(nr>=0 && nr<R && nc>=0 && nc<C && !visited[map[nr][nc]]){
            visited[map[nr][nc]] = true;
            dfs(nr, nc, cnt+1);
            visited[map[nr][nc]] = false;
        }
    }
}

int main(){
    cin>>R>>C;
    string s;
    for(int i=0; i<R; i++){
        cin>>s;
        for(int j=0; j<C; j++){
            map[i][j] = int(s[j]) - 'A';
        }
    }
    visited[map[0][0]] = true;
    dfs(0, 0, 1);
    cout<<maxCnt;
}
