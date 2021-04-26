#include <iostream>
#include <queue>
using namespace std;

struct triple{
    int z;
    int y;
    int x;
};

int m,n,h,cnt;
int tomato[101][101][101];
queue<triple> q;  //(z,y,x)
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

bool isInside(int y, int x, int z){
    if(x>=0 && x<m && y>=0 && y<n && z>=0 && z<h) return true;
    else    return false;
}

void bfs(){
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        
        q.pop();
        for(int i=0; i<6; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + dz[i];
            
            if(isInside(ny, nx, nz) && tomato[nz][ny][nx]==0){
                tomato[nz][ny][nx] = tomato[z][y][x] + 1;
                q.push({nz,ny,nx});
            }
        }
    }
}

int main(){
    cin>>m>>n>>h;
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    cin>>tomato[k][i][j];
                    if(tomato[k][i][j] == 1)   q.push({k,i,j});
                }
            }
    }
  
    bfs();
    
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(tomato[k][i][j] == 0){
                        cout<<"-1";
                        return 0;
                    }
                    if(cnt < tomato[k][i][j])  cnt = tomato[k][i][j];
                }
            }
    }
    cout<<cnt-1;
}
