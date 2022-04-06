#include <iostream>
#include <vector>
using namespace std;

int N,x,y,d,g;
bool map[102][102];
int direction[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}}; // {x,y}
int cnt;
vector<int> curve;

void dfs(int x, int y, int generate){
    if(generate == g+1) return;
    int curveSize = curve.size();
    for(int i=curveSize-1; i>=0; i--){
        int cd = (curve[i] + 1) % 4;
        x += direction[cd][0];
        y += direction[cd][1];
        if(x>=0 && x<=100 && y>=0 && y<=100) map[y][x] = true;
        curve.push_back(cd);
    }
    dfs(x, y, generate+1);
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>x>>y>>d>>g;
        curve.clear();
        map[y][x] = true;
        x += direction[d][0];
        y += direction[d][1];
        if(x>=0 && x<=100 && y>=0 && y<=100) map[y][x] = true;
        curve.push_back(d);
        dfs(x, y, 1);
    }
    
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]) cnt++;
        }
    }
    cout<<cnt;
}
