//
//  main.cpp
//  7569_2
//
//  Created by 홍세은 on 2022/03/14.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct box {
    int h,r,c;
    int d;
};

int M,N,H;
int tomato[101][101][101];
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dh[6] = {0,0,0,0,-1,1};
int day;
queue<box> q;

bool isInside(int r, int c, int h) {
    return r>=0 && r<N && c>=0 && c<M && h>=0 && h<H;
}

void bfs(){
    while (!q.empty()) {
        int curH = q.front().h;
        int curR = q.front().r;
        int curC = q.front().c;
        int curDay = q.front().d;
        day = max(day, curDay);
        q.pop();
        for(int i=0; i<6; i++){
            int nextH = curH + dh[i];
            int nextR = curR + dy[i];
            int nextC = curC + dx[i];
            if(isInside(nextR, nextC, nextH) && tomato[nextH][nextR][nextC] == 0) {
                tomato[nextH][nextR][nextC] = 1;
                q.push({nextH,nextR,nextC, curDay+1});
            }
        }
    }
}

int main(){
    cin>>M>>N>>H;
    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                cin>>tomato[i][j][k];
                if(tomato[i][j][k] == 1) {
                    q.push({i,j,k,0});
                }
            }
        }
    }
    
    if(q.size() == H*M*N) {
        cout<<0;
        return 0;
    }
    
    bfs();
    
    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                if(tomato[i][j][k] == 0){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    
    cout<<day<<"\n";
}
