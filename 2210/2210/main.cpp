//
//  main.cpp
//  2210
//
//  Created by 홍세은 on 2022/08/01.
//

#include <iostream>
#include <map>
using namespace std;

int board[5][5];
map<string, int> m;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

void dfs(int r, int c, string s) {
    if(s.size() == 6) {
        m.insert({s,0});
        return;
    }
    for(int i=0; i<4; i++) {
        int nr = r+dy[i];
        int nc = c + dx[i];
        if(nr < 0 || nr > 4 || nc < 0 || nc > 4) continue;
        dfs(nr, nc, s + to_string(board[nr][nc]));
    }
}

int main(){
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin>>board[i][j];
        }
    }
    
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            dfs(i, j, "");
        }
    }
    
    cout<<m.size();
}
