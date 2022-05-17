//
//  main.cpp
//  14500
//
//  Created by 홍세은 on 2022/05/17.
//

#include <iostream>
#include <cstring>
using namespace std;

int N,M;
int map[501][501];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int rowRec[3][2] = {{0,0},{0,1},{0,2}};
int colRec[3][2] = {{0,0},{1,0},{2,0}};
int result;

void getSum(int cnt, int sum, int r, int c, bool visited[501][501]){
    
    if(cnt == 3){
        result = max(result, sum);
        return;
    }
    
    for(int i=0; i<4; i++){
        int nr = r + dy[i];
        int nc = c + dx[i];
        if(nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc]){
            visited[nr][nc] = true;
            getSum(cnt+1, sum + map[nr][nc], nr, nc, visited);
            visited[nr][nc] = false;
        }
    }
}

void getSum2(int r, int c) {

    if(r-1 >= 0 && r-1 < N && c+1 >= 0 && c+1 < M) {
        int sumR = map[r-1][c+1];
        for(int i=0; i<3; i++){
            int nr = r + rowRec[i][0];
            int nc = c + rowRec[i][1];
            if(nr >= 0 && nr < N && nc >= 0 && nc < M){
                sumR += map[nr][nc];
            }
        }
        result = max(result, sumR);
    }
    
    if(r+1 >= 0 && r+1 < N && c+1 >= 0 && c+1 < M) {
        int sumR = map[r+1][c+1];
        for(int i=0; i<3; i++){
            int nr = r + rowRec[i][0];
            int nc = c + rowRec[i][1];
            if(nr >= 0 && nr < N && nc >= 0 && nc < M){
                sumR += map[nr][nc];
            }
        }
        result = max(result, sumR);
    }
    
    if(r+1 >= 0 && r+1 < N && c-1 >= 0 && c-1 < M) {
        int sumC = map[r+1][c-1];
        for(int i=0; i<3; i++){
            int nr = r + colRec[i][0];
            int nc = c + colRec[i][1];
            if(nr >= 0 && nr < N && nc >= 0 && nc < M){
                sumC += map[nr][nc];
            }
        }
        result = max(result, sumC);
    }
    
    if(r+1 >= 0 && r+1 < N && c+1 >= 0 && c+1 < M) {
        int sumC = map[r+1][c+1];
        for(int i=0; i<3; i++){
            int nr = r + colRec[i][0];
            int nc = c + colRec[i][1];
            if(nr >= 0 && nr < N && nc >= 0 && nc < M){
                sumC += map[nr][nc];
            }
        }
        result = max(result, sumC);
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            bool visited[501][501] = {false,};
            visited[i][j] = true;
            getSum(0, map[i][j], i, j, visited);
            getSum2(i, j);
        }
    }
    cout<<result;
}
