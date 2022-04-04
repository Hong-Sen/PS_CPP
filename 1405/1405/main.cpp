#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int percent[4];  // E,W,S,N
int coordinate[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}}; // E,W,S,N
string direction = "0123";
bool isVisited[30][30];
double sum;

void dfs(int time, int r, int c, double chance){
    isVisited[r][c] = true;
    if(time == N){
        sum += chance;
        return;
    }
    for(int i=0; i<4; i++){
        int nr = r + coordinate[i][0];
        int nc = c + coordinate[i][1];
        if(isVisited[nr][nc]) continue;
        isVisited[nr][nc] = true;
        dfs(time+1, nr, nc, chance * 0.01 * percent[i]);
        isVisited[nr][nc] = false;
    }
}

int main(){
    cin>>N;
    for(int i=0; i<4; i++){
        cin>>percent[i];
    }
    dfs(0, 14, 14, 1.0);
    cout<<fixed;
    cout.precision(10);
    cout<<sum<<"\n";
}
