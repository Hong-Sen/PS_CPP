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

void dfs(int row, int col, int dir){
    // 청소 = 9
    map[row][col] = 9;
    // 네 방향 모두 청소 or 벽
    if(map[row][col-1] != 0 && map[row-1][col] != 0 && map[row][col+1] != 0 && map[row+1][col] != 0) {
        // c. 네 방향 모두 청소 or 벽 + 뒤쪽 방향 벽x
        // d. 네 방향 모두 청소 or 벽 + 뒤쪽 방향 벽o
        switch (dir) {
            case 0:
                if(map[row+1][col] == 9) dfs(row+1, col, dir);
                else return;
                break;
            case 1:
                if(map[row][col-1] == 9) dfs(row, col-1, dir);
                else return;
                break;
            case 2:
                if(map[row-1][col] == 9) dfs(row-1, col, dir);
                else return;
                break;
            case 3:
                if(map[row][col+1] == 9) dfs(row, col+1, dir);
                else return;
                break;
            default:
                break;
        }
    }
    else{
        // isLeftBlank -> a. 왼쪽 방향으로 회전 후 전진
        // !isLeftBlank -> b. 왼쪽 방향으로 회전
        switch (dir) {
            case 0:
                if(map[row][col-1] == 0) dfs(row, col-1, 3);
                else dfs(row, col, 3);
                break;
            case 1:
                if(map[row-1][col] == 0) dfs(row-1, col, 0);
                else dfs(row, col, 0);
                break;
            case 2:
                if(map[row][col+1] == 0) dfs(row, col+1, 1);
                else dfs(row, col, 1);
                break;
            case 3:
                if(map[row+1][col] == 0) dfs(row+1, col, 2);
                else dfs(row, col, 2);
                break;
            default:
                break;
        }
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
