#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m,n,k;
int paper[101][101];
bool visited[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<int> result;
int cnt;

void paint(int lx,int ly,int rx, int ry){
    for(int i=ry; i<ly; i++){
        for(int j=lx; j<rx; j++){
            paper[i][j] = 1;
        }
    }
}

bool isInside(int x, int y){
    if(x>=0 && y>=0 && x<n && y<m)  return true;
    else    return false;
}

void bfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(isInside(nx, ny) && !visited[ny][nx] && paper[ny][nx] == 0){
            visited[ny][nx] = true;
            cnt++;
            bfs(nx, ny);
        }
    }
}

int main(){
    cin>>m>>n>>k;
    int lx,ly,rx,ry;
    for(int i=0; i<k; i++){
        cin>>lx>>ly>>rx>>ry;
        paint(lx, m-ly, rx, m-ry);
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && paper[i][j] == 0){
                cnt = 0;
                bfs(j, i);
                if(cnt == 0)    cnt = 1;
                result.push_back(cnt);
            }
        }
    }
    sort(result.begin(), result.end());
    cout<<result.size()<<"\n";
    for(int i:result){
        cout<<i<<" ";
    }
}

