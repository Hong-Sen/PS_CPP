#include <iostream>
#include <vector>
#include <queue>
#define INF 500001
using namespace std;

vector<pair<int,int>> adj[2001];
int result[2001];
priority_queue<pair<int,int>> pq;

void dijkstra(int start) {
    pq.push({0,start});
    result[start] = 0;
    while(!pq.empty()) {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(result[node] < cost) continue;
        for(int i=0; i<adj[node].size(); i++) {
            int next = adj[node][i].first;
            int nextCost = adj[node][i].second + cost;
            if(result[next] > nextCost) {
                result[next] = nextCost;
                pq.push({-nextCost, next});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 1;
    for(int i=1; i<=N; i++) {
        result[i] = INF;
    }
    for(int i=0; i<road.size(); i++) {
        adj[road[i][0]].push_back({road[i][1], road[i][2]});
        adj[road[i][1]].push_back({road[i][0], road[i][2]});
    }

    dijkstra(1);
    
    for(int i=2; i<=N; i++) {
        if(result[i] <= K) answer++;
    }
    
    return answer;
}
