#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int TC,N,M,W;
int S,E,T;
vector<pair<int, pair<int, int>>> road;
int dist[501];
bool flag;

void bellman_ford(){
    dist[1] = 0;
    for(int i=1; i<N; i++){
        for(int j=0; j<road.size(); j++){
            int from = road[j].first;
            int to = road[j].second.first;
            int cost = road[j].second.second;
            if(dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
        }
    }
    
    for(int j=0; j<road.size(); j++){
        int from = road[j].first;
        int to = road[j].second.first;
        int cost = road[j].second.second;
        if(dist[from] == INF) continue;
        if(dist[to] > dist[from] + cost){
            flag = true;
            break;
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
}


int main(){
    cin>>TC;
    for(int i=0; i<TC; i++){
        cin>>N>>M>>W;
        road.clear();
        flag = false;
        for(int j=1; j<=N; j++)
            dist[j] = INF;
        
        for(int j=0; j<M; j++){
            cin>>S>>E>>T;
            road.push_back({S,{E,T}});
            road.push_back({E,{S,T}});
        }
        for(int j=0; j<W; j++){
            cin>>S>>E>>T;
            road.push_back({S,{E,-T}});
        }
        bellman_ford();
    }
}
