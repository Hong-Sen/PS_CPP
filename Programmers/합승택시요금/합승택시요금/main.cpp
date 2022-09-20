#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int costEach[201][201];
vector<pair<int,int>> road[201];

void dijkstra(int start) {
    costEach[start][start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    while(!pq.empty()) {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(costEach[start][node] < cost) continue;
        for(int i=0; i<road[node].size(); i++) {
            int nextNode = road[node][i].first;
            int nextCost = road[node][i].second + cost;
            if(costEach[start][nextNode] > nextCost) {
                costEach[start][nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
             costEach[i][j] = INF;
        }
    }
    
    for(int i=0; i<fares.size(); i++) {
        road[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        road[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    
    for(int i=1; i<=n; i++) {
        dijkstra(i);
    }
    
    long long minCost = costEach[s][a] + costEach[s][b];
    for(int i=1; i<=n; i++) {
        if(i == s) continue;
        if(minCost > costEach[s][i] + costEach[i][a] + costEach[i][b])
            minCost = costEach[s][i] + costEach[i][a] + costEach[i][b];
    }
    
    return minCost;
}
