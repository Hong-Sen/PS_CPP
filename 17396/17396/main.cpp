#include <iostream>
#include <queue>
#include <vector>
#define INF 99999999999
using namespace std;

int n,m;
int a,b,t;
vector<pair<int, int>> v[100001];
bool sight[100001];
long long dist[100001];
priority_queue<pair<long long, int>> pq;

void dijkstra(){
    dist[0] = 0;
    pq.push({0,0});
    while (!pq.empty()) {
        int curNode = pq.top().second;
        long long curCost = -pq.top().first;
        pq.pop();
        if(dist[curNode] < curCost) continue;
        for(int i=0; i<v[curNode].size(); i++){
            int nextNode = v[curNode][i].first;
            long long nextCost = v[curNode][i].second + curCost;
            if(dist[nextNode] > nextCost){
                dist[nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x == 1)  sight[i] = false;
        else sight[i] = true;
        if(i==n-1) sight[i] = true;
        dist[i] = INF;
    }
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>t;
        if(!sight[a] || !sight[b])  continue;
        v[a].push_back({b,t});
        v[b].push_back({a,t});
    }
    
    dijkstra();
   
    if(dist[n-1] == INF) cout<<"-1";
    else cout<<dist[n-1];
}
