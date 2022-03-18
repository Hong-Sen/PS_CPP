//
//  main.cpp
//  14503
//
//  Created by 홍세은 on 2022/03/18.
//

#include <iostream>
#include <vector>
using namespace std;

int N,M,r,c,d;
int map[51][51];
int cnt;
int direction[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};

void dfs(int row, int col, int dir){
    map[row][col] = 9;
    int nextR = 0;
    int nextC = 0;
    
    // 네 방향 모두 청소 or 벽
    if(map[row][col-1] != 0 && map[row-1][col] != 0 && map[row][col+1] != 0 && map[row+1][col] != 0) {
        // 뒤쪽 방향 구하기
        switch (dir) {
            case 0:
                nextR = row+1;
                nextC = col;
                break;
            case 1:
                nextR = row;
                nextC = col-1;
                break;
            case 2:
                nextR = row-1;
                nextC = col;
                break;
            case 3:
                nextR = row;
                nextC = col+1;
                break;
            default:
                break;
        }
        // c. 네 방향 모두 청소 or 벽 + 뒤쪽 방향 벽x
        if(map[nextR][nextC] == 9) {
            dfs(nextR, nextC, dir);
            return;
        }
        // d. 네 방향 모두 청소 or 벽 + 뒤쪽 방향 벽o
        else {
            return;
        }
    }
    
    // 왼쪽 방향 구하기
    nextR = row + direction[dir][0];
    nextC = col + direction[dir][1];

    bool isLeftBlank = false;
    if(map[nextR][nextC] == 0) isLeftBlank = true;
    
    // isLeftBlank -> a. 왼쪽 방향으로 회전 후 전진
    // !isLeftBlank -> b. 왼쪽 방향으로 회전 후 전진
    switch (dir) {
        case 0:
            isLeftBlank ? dfs(nextR, nextC, 3) :  dfs(row, col, 3);
            break;
        case 1:
            isLeftBlank ? dfs(nextR, nextC, 0) :  dfs(row, col, 0);
            break;
        case 2:
            isLeftBlank ? dfs(nextR, nextC, 1) :  dfs(row, col, 1);
            break;
        case 3:
            isLeftBlank ? dfs(nextR, nextC, 2) :  dfs(row, col, 2);
            break;
        default:
            break;
    }
}

int main(){
    cin>>N>>M>>r>>c>>d;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    dfs(r, c, d);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 9) cnt++;
        }
    }
    cout<<cnt;
}
