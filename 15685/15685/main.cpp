#include <iostream>
#include <vector>
using namespace std;

int N,x,y,d,g;
bool map[102][102];
int direction[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}}; // {x,y}
int square[4][2] = {{0,0}, {1,0}, {0,1}, {1,1}};
int cnt;
vector<int> curve;

bool isInside(int x, int y){
    return x>=0 && x<=100 && y>=0 && y<=100;
}

void dfs(int x, int y, int generate){
    if(generate == g+1) return;
    if(generate == 0){
        map[y][x] = true;
        x += direction[d][0];
        y += direction[d][1];
        if(isInside(x, y)) map[y][x] = true;
        curve.push_back(d);
        dfs(x, y, generate+1);
        return;
    }
    int curveSize = curve.size();
    for(int i=curveSize-1; i>=0; i--){
        int cd = (curve[i] + 1) % 4;
        x += direction[cd][0];
        y += direction[cd][1];
        if(isInside(x, y)) map[y][x] = true;
        curve.push_back(cd);
    }
    dfs(x, y, generate+1);
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>x>>y>>d>>g;
        curve.clear();
        dfs(x, y, 0);
    }
    
    for(int i=0; i<102; i++){
        for(int j=0; j<102; j++){
            bool flag = true;
            for(int k=0; k<4; k++){
                int nx = j + square[k][0];
                int ny = i + square[k][1];
                if(!isInside(nx, ny) || !map[ny][nx]){
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
    }
    cout<<cnt;
}
