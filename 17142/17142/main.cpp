//
//  main.cpp
//  17142
//
//  Created by 홍세은 on 2022/09/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
int map[51][51];
vector<pair<int, int>> virus;
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int result = 987654321;
int blanckCnt;
bool isPossible;

void bfs(vector<pair<int, int>> settingVirus) {
    int maxTime = 0, removeBlank = 0;
    queue<pair<int,int>> q;
    int spreadMap[51][51];
    
    for(int i=0; i<N; i++ ){
        for(int j=0; j<N; j++) {
            spreadMap[i][j] = map[i][j];
        }
    }
    
    for(auto i: virus) {
        spreadMap[i.first][i.second] = -1;
    }
    
    for(auto i: settingVirus) {
        q.push({i.first, i.second});
        spreadMap[i.first][i.second] = 1;
    }
    
    while (!q.empty()) {
        if(removeBlank == blanckCnt) {
            break;
        }
        int r = q.front().first;
        int c = q.front().second;
        int cost = spreadMap[r][c];
        
        q.pop();
        for(int i=0; i<4; i++) {
            int nextR = r + dxy[i][0];
            int nextC = c + dxy[i][1];
            if(nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) continue;
            if(spreadMap[nextR][nextC] == -1) {
                spreadMap[nextR][nextC] = cost + 1;
                q.push({nextR, nextC});
            }
            else if(spreadMap[nextR][nextC] == 0) {
                removeBlank++;
                spreadMap[nextR][nextC] = cost + 1;
                q.push({nextR, nextC});
            }
            else if(spreadMap[nextR][nextC] != -2) {
                if(spreadMap[nextR][nextC] > cost+1) {
                    spreadMap[nextR][nextC] = cost + 1;
                    q.push({nextR, nextC});
                }
            }
        }
    }
    
    bool flag = true;
    for(int i=0; i<N; i++ ){
        if(!flag) break;
        for(int j=0; j<N; j++) {
            if(spreadMap[i][j] == 0){
                flag = false;
                break;
            }
            maxTime = max(maxTime, spreadMap[i][j] - 1);
        }
    }
    
    if(flag) {
        isPossible = true;
        result = min(result, maxTime);
    }
}

void setActiveVirus(int idx, vector<pair<int, int>> settingVirus) {
    if(settingVirus.size() == M) {
        bfs(settingVirus);
        return;
    }
    
    if(idx >= virus.size()) return;
    
    for(int i=idx; i<virus.size(); i++) {
        settingVirus.push_back({virus[i].first, virus[i].second});
        setActiveVirus(i+1, settingVirus);
        settingVirus.pop_back();
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>map[i][j];
            switch(map[i][j]) {
                case 0:
                    blanckCnt++;
                    break;
                case 1:
                    map[i][j] = -2;
                    break;
                case 2:
                    virus.push_back({i,j});
                    break;
            }
        }
    }
    
    if(blanckCnt == 0) {
        cout<<"0";
        return 0;
    }
    
    vector<pair<int, int>> v;
    setActiveVirus(0, v);

    if(!isPossible) cout<<"-1";
    else cout<<result;
}
