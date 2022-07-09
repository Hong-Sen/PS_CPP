//
//  main.cpp
//  10217
//
//  Created by 홍세은 on 2022/07/09.
//

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int T,N,M,K;
int dist[101][10001]; // [도착공항][1공항 부터 도착공항까지 가는데에 비용]
struct ticket {
    int v,c,d;  // 도착공항, 비용, 소요시간
};

vector<ticket> adj[101]; // adj[출발공항] = {도착공항, 비용, 소요시간}

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq; // {시간, 비용, 도착공항}
    pq.push({0,{0,1}});
    dist[1][0] = 0;
    while (!pq.empty()) {
        int time = -pq.top().first;
        int cost = pq.top().second.first;
        int node = pq.top().second.second;
        pq.pop();
        if(dist[node][cost] < time) continue;
        for(int i=0; i<adj[node].size(); i++) {
            int nextNode = adj[node][i].v;
            int nextCost = adj[node][i].c + cost;
            int nextTime = adj[node][i].d + time;
            if(nextCost > M) continue;
            if(nextTime < dist[nextNode][nextCost]) {
                dist[nextNode][nextCost] = nextTime;
                pq.push({-nextTime,{nextCost,nextNode}});
            }
        }
    }
    
}

int main(){
    cin>>T;
    while (T--) {
        cin>>N>>M>>K;
        for(int i=1; i<=N; i++)
            adj[i].clear();
        
        while (K--) {
            int u,v,c,d;
            cin>>u>>v>>c>>d;
            adj[u].push_back({v,c,d});
        }

        for(int i=1; i<=N; i++) {
            for(int j=0; j<=M; j++) {
                dist[i][j] = INF;
            }
        }
        
        dijkstra();
        
        int result = INF;
        for(int i=0; i<=M; i++) {
            if(dist[N][i] < result) result = dist[N][i];
        }
        if(result == INF) cout<<"Poor KCM\n";
        else cout<<result<<"\n";
    }
}
