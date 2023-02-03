//
//  main.cpp
//  16197
//
//  Created by 홍세은 on 2023/02/03.
//

#include <iostream>
#include <vector>
using namespace std;

int N,M;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int btn = 11;

void dfs(vector<pair<int, int>> coin, char board[21][21], int cnt) {
//    cout<<"\n\ncnt: "<<cnt<<"\n";
//    for(int i=0; i<N; i++) {
//        for(int j=0; j<M; j++) {
//            cout<<board[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//
    if(cnt > 10) return;
    for(int i=0; i<4; i++) {
        int c1Next[2] = {coin[0].first + dx[i],coin[0].second + dy[i]};
        int c2Next[2] = {coin[1].first + dx[i],coin[1].second + dy[i]};
//        cout<<c1Next[0]<<" "<<c1Next[1]<<"\n";
//        cout<<c2Next[0]<<" "<<c2Next[1]<<"\n";
        if(c1Next[0] < 0 || c1Next[0] >= N || c1Next[1] < 0 || c1Next[1] >= M) {
            if(c2Next[0] < 0 || c2Next[0] >= N || c2Next[1] < 0 || c2Next[1] >= M) continue;
            else {
                btn = min(btn, cnt);
                continue;
            }
        }
        else if(c2Next[0] < 0 || c2Next[0] >= N || c2Next[1] < 0 || c2Next[1] >= M) {
            if(c1Next[0] < 0 || c1Next[0] >= N || c1Next[1] < 0 || c1Next[1] >= M) return;
            else {
                btn = min(btn, cnt);
                continue;
            }
        }
        
        if(board[c1Next[0]][c1Next[1]] == '#') {
            if(board[c2Next[0]][c2Next[1]] == '#') {
                dfs(coin, board, cnt+1);
            }
            else if(board[c2Next[0]][c2Next[1]] == '.' || board[c2Next[0]][c2Next[1]] == 'o') {
                vector<pair<int, int>> tmpCoin;
                tmpCoin.push_back(coin[0]);
                tmpCoin.push_back({c2Next[0], c2Next[1]});
                char origin = board[coin[1].first][coin[1].second];
                char nextOrigin = board[c2Next[0]][c2Next[1]];
                board[c2Next[0]][c2Next[1]] = 'o';
                board[coin[1].first][coin[1].second] = '.';
                dfs(tmpCoin, board, cnt+1);
                board[c2Next[0]][c2Next[1]] = nextOrigin;
                board[coin[1].first][coin[1].second] = origin;
            }
        }
        else if(board[c1Next[0]][c1Next[1]] == '.' || board[c1Next[0]][c1Next[1]] == 'o')  {
            if(board[c2Next[0]][c2Next[1]] == '#') {
                vector<pair<int, int>> tmpCoin;
                tmpCoin.push_back({c1Next[0], c1Next[1]});
                tmpCoin.push_back(coin[1]);
                
                char origin = board[coin[0].first][coin[0].second];
                char originNext = board[c1Next[0]][c1Next[1]];
                board[c1Next[0]][c1Next[1]] = 'o';
                board[coin[0].first][coin[0].second] = '.';
                
                dfs(tmpCoin, board, cnt+1);
                
                board[c1Next[0]][c1Next[1]] = originNext;
                board[coin[0].first][coin[0].second] = origin;
            }
            else if(board[c2Next[0]][c2Next[1]] == '.' || board[c2Next[0]][c2Next[1]] == 'o') {
                vector<pair<int, int>> tmpCoin;
                tmpCoin.push_back({c1Next[0], c1Next[1]});
                tmpCoin.push_back({c2Next[0], c2Next[1]});
                
                board[coin[0].first][coin[0].second] = '.';
                board[coin[0].first][coin[0].second] = '.';
                board[c1Next[0]][c1Next[1]] = 'o';
                board[c2Next[0]][c2Next[1]] = 'o';
                
                dfs(tmpCoin, board, cnt+1);
            }
        }
    }
}

int main() {
    cin>>N>>M;
    char board[21][21];
    vector<pair<int, int>> coin;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>board[i][j];
            if(board[i][j] == 'o') {
                coin.push_back({i,j});
            }
        }
    }
    
    dfs(coin, board, 1);
    if(btn > 10) cout<<-1;
    else cout<<btn;
}
