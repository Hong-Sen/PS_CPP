// 09.31m
#include <iostream>
using namespace std;

int M,N;
int map[101][101];
int cnt;
int num;
int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // {우,하,좌,상}

void dfs(int r, int c, int dir) {
    map[r][c] = ++num;
    if(num == M*N) return;
    int nr = r + d[dir][0];
    int nc = c + d[dir][1];
    if(nr < 0 || nc < 0 || nr >= M || nc >= N || map[nr][nc] != 0) {
        cnt++;
        dir = (dir + 1) % 4;
        nr = r + d[dir][0];
        nc = c + d[dir][1];
    }
    dfs(nr, nc, dir);
}

int main() {
    cin>>M>>N;
    dfs(0, 0, 0);
    cout<<cnt;
}
