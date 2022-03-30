//
//  main.cpp
//  9205
//
//  Created by 홍세은 on 2022/03/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int t, n, x, y;
vector<int> adj[102];
bool isVisited[102];

int dis(pair<int, int>a, pair<int, int>b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int node){
    isVisited[node] = true;
    for(int i=0; i<adj[node].size(); i++){
        int next = adj[node][i];
        if(!isVisited[next]) dfs(next);
    }
}

int main(){
    cin>>t;
    while (t--) {
        for(int i=0; i<102; i++){
            adj[i].clear();
            isVisited[i] = false;
        }
        
        cin>>n;
        vector<pair<int, int>> market;
        
        // 출발점, 도착점 포함
        for(int i=0; i<n+2; i++){
            int x,y;
            cin>>y>>x;
            market.push_back({y,x});
        }
        
        // 거리가 1000이하면 그래프 추가
        for(int i=0; i<n+2; i++){
            for(int j=i+1; j<n+2; j++){
                if(dis(market[i], market[j]) <= 1000){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        dfs(0);
        
        // n+1 = 도착점
        if(isVisited[n+1]) cout<<"happy\n";
        else cout<<"sad\n";
    }
}
