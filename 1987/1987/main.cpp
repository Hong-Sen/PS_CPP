#include <iostream>
#include <algorithm>
using namespace std;

int r,c;
int map[21][21];
bool visited[27];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int result;

bool isInside(int y, int x){
    if(y>=0 && x>=0 && y<r && x<c)  return true;
    else    return false;
}

void dfs(int y, int x, int cnt){
    result = max(result, cnt);
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isInside(ny, nx) && !visited[map[ny][nx]]){
            visited[map[ny][nx]] = true;
            dfs(ny, nx, cnt+1);
            visited[map[ny][nx]] = false;
        }
    }
}

int main(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        string s;
        cin>>s;
        for(int j=0; j<c; j++){
            map[i][j] = s.at(j) - 'A';
        }
    }

    visited[map[0][0]] = true;
    dfs(0, 0, 1);
    cout<<result<<"\n";
}
