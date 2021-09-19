#include <iostream>
using namespace std;

int n;
char color[101][101];
char colorRB[101][101];
bool visitedRGB[101][101];
bool visitedRB[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int cntRGB, cntRB;

bool isInside(int x, int y){
    if(x>=0 && y>=0 && x<n && y<n)  return true;
    else return false;
}

//적록색약이 아닌 사람용 bfs
void bfsRGB(int x, int y, char paint){
    for(int i=0; i<4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(isInside(nx, ny) && !visitedRGB[ny][nx] && color[ny][nx] == paint){
            visitedRGB[ny][nx] = true;
            bfsRGB(nx, ny, paint);
        }
    }
}

//적록색약 사람용 bfs
void bfsRB(int x, int y, char paint){
    for(int i=0; i<4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(isInside(nx, ny) && !visitedRB[ny][nx] && colorRB[ny][nx] == paint){
            visitedRB[ny][nx] = true;
            bfsRB(nx, ny, paint);
        }
    }
}

int main(){
    cin>>n;
    char c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>c;
            color[i][j] = c;
            if(c == 'G') colorRB[i][j] = 'R';
            else colorRB[i][j] = c;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visitedRGB[i][j]){
                bfsRGB(j,i, color[i][j]);
                cntRGB++;
            }
            if(!visitedRB[i][j]){
                bfsRB(j,i,colorRB[i][j]);
                cntRB++;
            }
        }
    }
    cout<<cntRGB<<" "<<cntRB;
}
