#include <iostream>
#include <cstring>
using namespace std;

int w,h;
int cnt;
int map[51][51];
bool visited[51][51];
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(int x, int y){
    if(y<h && x<w && y>=0 && x>=0)  return true;
    else    return false;
}

void dfs(int startY, int startX){
    visited[startY][startX] = true;
    for(int i=0; i<8; i++){
        int nextX = startX + dx[i];
        int nextY = startY + dy[i];
        if(isValid(nextX, nextY) && !visited[nextY][nextX] && map[nextY][nextX] == 1){
//            cout<<"startY: "<<startY<<" startX: "<<startX<<" nextY: "<<nextY<<" nextX:"<<nextX<<"\n";
            dfs(nextY, nextX);
        }
        
    }
}

int main(){
    w=1;
    h=1;
    while (1) {
        cin>>w>>h;
        if(w == 0 && h == 0)    break;;
        cnt = 0;
        memset(visited, false, sizeof(visited));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>map[i][j];
            }
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(!visited[i][j] && map[i][j]==1){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
}
