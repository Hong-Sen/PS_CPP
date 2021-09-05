#include <iostream>
#include <queue>
#include <vector>
#define INF 999999999
using namespace std;

int n,m;
int a,b,c;
vector<pair<int, int>> adj[50001];
priority_queue<pair<int, int>> pq; //{정점, 비용}
int dist[50001];

void dijkstra(int start){
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cost = -pq.top().first; //min-heap을 이용하기 위해 -를 붙임.
        int node = pq.top().second;
        pq.pop();
        if(dist[node] < cost)   continue;
        for(int i=0; i<adj[node].size(); i++){
            int nextNode = adj[node][i].first;
            int nextCost = adj[node][i].second + cost;
            if(nextCost < dist[nextNode]){
                dist[nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<=n; i++){
        dist[i] = INF;
    }
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    
    dijkstra(1);
    
    cout<<dist[n];
}
