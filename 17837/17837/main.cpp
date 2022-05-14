//
//  main.cpp
//  17838_2
//
//  Created by 홍세은 on 2022/05/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct horse {
    int r,c,d;
} h[10];
int N,K;
int map[15][15];
int dxy[5][2] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};
vector<int> chess[15][15];
int cnt;

int findIdx(int i){
    for(int j=0; j<chess[h[i].r][h[i].c].size(); j++){
        if(i == chess[h[i].r][h[i].c][j]) return j;
    }
    return 100;
}

bool play(){
    for(int i=0; i<K; i++){
        int nr = h[i].r + dxy[h[i].d][0];
        int nc = h[i].c + dxy[h[i].d][1];
        
        if(nr <= 0 || nr > N || nc <= 0 || nc > N || map[nr][nc] == 2){
            h[i].d = h[i].d % 2 == 0 ? h[i].d - 1 : h[i].d + 1;
            nr = h[i].r + dxy[h[i].d][0];
            nc = h[i].c + dxy[h[i].d][1];
            
            if(nr <= 0 || nr > N || nc <= 0 || nc > N || map[nr][nc] == 2) continue;
        }
        
        int idx = findIdx(i);
        vector<int> cur;
        
        for(int j=idx; j<chess[h[i].r][h[i].c].size(); j++){
            cur.push_back(chess[h[i].r][h[i].c][j]);
        }
        
        if(map[nr][nc] == 1) {
            reverse(cur.begin(), cur.end());
        }
        
        for(int j=chess[h[i].r][h[i].c].size()-1; j>=idx; j--){
            chess[h[i].r][h[i].c].pop_back();
        }
        
        // 이동
        for(int i=0; i<cur.size(); i++){
            chess[nr][nc].push_back(cur[i]);
            if(chess[nr][nc].size() >= 4) return false;
            h[cur[i]].r = nr;
            h[cur[i]].c = nc;
        }
    }
    return true;
}

int main(){
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<K; i++){
        cin>>h[i].r>>h[i].c>>h[i].d;
        chess[h[i].r][h[i].c].push_back(i);
    }
    
    while (1) {
        cnt++;
        if(!play()){
            cout<<cnt;
            break;
        }
        if(cnt > 1000){
            cout<<"-1";
            break;
        }
    }
}
