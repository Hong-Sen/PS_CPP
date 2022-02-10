//
//  main.cpp
//  11779
//
//  Created by 홍세은 on 2022/02/10.
//

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n,m,a,b,c,start,finish;
vector<pair<int, int>> adj[1001];
int dist[1001];
int before[1001];
//vector<int> path[1001];

void dijkstra(int s){
    priority_queue<pair<int, int>> pq;
    pq.push({0,s});
    dist[s] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        cout<<cur<<" ";
        if(cost > dist[cur]) continue;
        for(int i=0; i<adj[cur].size(); i++){
            int next = adj[cur][i].first;
            int nextCost = adj[cur][i].second + cost;
            if(nextCost > dist[next]){
                continue;
            }
            before[next] = cur;
            dist[next] = nextCost;
            pq.push({-nextCost, next});
        }
    }

    for(int i=1; i<=n; i++)
        cout<<before[i]<<" ";
    cout<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        if(adj[a].empty())  adj[a].push_back({b,c});
        else {
            if(adj[a][0].second > c){
                adj[a][0].first = b;
                adj[a][0].second = c;
            }
        }
    }
    cin>>start>>finish;
    
    dijkstra(start);
    
    vector<int> path;
    int i = finish;
        while (i) {
            path.push_back({i});
            i = before[i];
        }
    cout<<dist[finish]<<"\n"<<path.size()<<"\n";
    for(int i=path.size()-1; i>=0; i--){
        cout<<path[i]<<" ";
    }
}
