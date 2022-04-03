#include <iostream>
#include <vector>
using namespace std;

int R,C;
string map[21];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
bool visited['Z'+1];
int maxCnt;

void dfs(int r, int c, int cnt){
    if(r<0 || r>= R || c<0 || c>=C || visited[map[r][c]]) return;
    maxCnt = max(cnt, maxCnt);
    visited[map[r][c]] = true;
    for(int i=0; i<4; i++){
        int nr = r + dy[i];
        int nc = c + dx[i];
        dfs(nr, nc, cnt+1);
    }
    visited[map[r][c]] = false;
}

int main(){
    cin>>R>>C;
    string s;
    for(int i=0; i<R; i++){
        cin>>map[i];
    }
   
    dfs(0, 0, 1);
    cout<<maxCnt;
}
