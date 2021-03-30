#include <iostream>
#include <queue>
#include <vector>
#define INF 999999
using namespace std;

int n,m,k;
int dis[20001];
vector<pair<int, int>> vc[300001];

void dijkstra(int start){
    dis[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({dis[start],start});
    
    while (!pq.empty()) {
        int cur = pq.top().second;
        int distance = pq.top().first * -1;
        pq.pop();
        if(dis[cur] < distance) continue;
        for(int i=0; i<vc[cur].size(); i++){
            int next = vc[cur][i].first;
            int nextDis = distance + vc[cur][i].second;
            if(nextDis < dis[next]){
                dis[next] = nextDis;
                pq.push({nextDis*-1, next});
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    
    for(int i=1; i<=n; i++)
        dis[i] = INF;
    
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        vc[u].push_back({v,w});
    }
    
    dijkstra(k);
    
    for(int i=1; i<=n; i++){
        if(dis[i] != INF)
        cout<<dis[i]<<"\n";
        else
            cout<<"INF"<<"\n";
    }
}
