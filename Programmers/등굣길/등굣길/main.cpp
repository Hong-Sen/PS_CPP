#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int M,N;
int dp[101][101];
int cnt[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<vector<int>> pud;
queue<pair<int,int>> q;
bool isBlock; // 학교로 가는 길이 전부 막힌 경우

bool isPuddles(int row, int col){
    for(int i=0; i<pud.size(); i++){
        if(row == pud[i][1] && col == pud[i][0]) return true;
    }
    return false;
}

bool isInside(int row, int col){
    return row >=1 && row <= N && col >=1 && col <=M;
}

void bfs(){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=M; j++){
            dp[i][j] = INF;
            cnt[i][j] = 1;
        }
    }
    q.push({1,1});
    dp[1][1] = 0;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        if(cr == N && cc == M)  isBlock = true;
        q.pop();
        for(int i=0; i<4; i++){
            int nr = cr + dy[i];
            int nc = cc + dx[i];
            if(!isPuddles(nr,nc) && isInside(nr,nc)){
                if(dp[nr][nc] == INF) q.push({nr,nc});
                if(dp[nr][nc] > dp[cr][cc] + 1){
                    dp[nr][nc] = dp[cr][cc] + 1;
                    cnt[nr][nc] = cnt[cr][cc];
                }
                else if(dp[nr][nc] == dp[cr][cc] + 1){
                    cnt[nr][nc] = (cnt[nr][nc] + cnt[cr][cc]) % 1000000007;
                }
            }
        }
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    M = m;
    N = n;
    pud = puddles;
    bfs();
    if(!isBlock) return 0;
    return cnt[n][m];
}
