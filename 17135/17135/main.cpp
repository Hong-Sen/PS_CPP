//
//  main.cpp
//  17135
//
//  Created by 홍세은 on 2022/07/07.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#define INF 987654321
using namespace std;

int N,M,D;
int board[17][17];
int maxCnt;
vector<pair<int, int>> enemy;

int attack(vector<int> archer) {
    int cnt = 0;
    vector<pair<int, int>> v = enemy;
    int newBoard[17][17];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            newBoard[i][j] = board[i][j];
        }
    }
    
    for(int a=0; a<N; a++) {
        if(v.empty()) break;
        // 공격가능한 적 찾기
        map<pair<int, int>, int> mp;
        for(int i=0; i<archer.size(); i++) {
            int minDis = INF;
            pair<int, int> rc;
            for(int j=0; j<v.size(); j++) {
                int dis = abs(N - v[j].first) + abs(archer[i] - v[j].second);
                if(dis <= D ) {
                    if(dis < minDis) {
                        minDis = dis;
                        rc.first = v[j].first;
                        rc.second = v[j].second;
                    }
                    else if(dis == minDis) {
                        if(rc.second > v[j].second) {
                            rc.first = v[j].first;
                            rc.second = v[j].second;
                        }
                    }
                }
            }
            if(minDis != INF) mp.insert({rc,0});
        }
        
        // 공격하기
        for(auto it = mp.begin(); it!= mp.end(); it++) {
            cnt++;
            newBoard[it->first.first][it->first.second] = 0;
        }
        
        // 적 이동시키기
        v.clear();
        for(int i=N-1; i>=0; i--) {
            for(int j=M-1; j>=0; j--) {
                if(newBoard[i][j] == 1) {
                    if(i+1 == N) newBoard[i][j] = 0;
                    else {
                        newBoard[i+1][j] = 1;
                        newBoard[i][j] = 0;
                        v.push_back({i+1, j});
                    }
                }
            }
        }
    }
    return cnt;
}

// 궁수 배치하기(모든 경우의 수 고려)
void arrayArcher(int idx, vector<int> archer) {
    if(archer.size() == 3) {
        maxCnt = max(maxCnt, attack(archer));
        return;
    }
    
    for(int i=idx; i<M; i++) {
        archer.push_back(i);
        arrayArcher(i+1, archer);
        archer.pop_back();
    }
}

int main(){
    cin>>N>>M>>D;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>board[i][j];
            if(board[i][j] == 1) {
                enemy.push_back({i,j});
            }
        }
    }
    vector<int> archer;
    arrayArcher(0, archer);
    
    cout<<maxCnt;
}
