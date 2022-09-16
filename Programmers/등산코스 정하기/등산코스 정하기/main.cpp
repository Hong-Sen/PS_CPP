#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int node[50001];
int intensity[50001];
vector<pair<int,int>> v[50001];
priority_queue<pair<int,int>> pq;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> result;
    result.push_back(0); // {summit,intensity};
    result.push_back(10000001);
    
    for(int i=1; i<=n; i++) intensity[i] = 10000001;
    for(auto p: paths) {
        v[p[0]].push_back({p[1], p[2]});
        v[p[1]].push_back({p[0], p[2]});
    }
    
    for(int i: summits) {
        node[i] = 2;
    }
    
    for(int i: gates) {
        intensity[i] = -1; // 다른 출입구로 이동하는 것 방지
        pq.push({0,i});
    }
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost > result[1]) continue;
        if(node[cur] == 2) {
            if(result[1] > cost) {
                result[1] = cost;
                result[0] = cur;
            }
            else if(result[1] == cost && result[0] > cur) {
                result[0] = cur;
            }
            continue;
        }
        
        for(int i=0; i<v[cur].size(); i++) {
            if(intensity[v[cur][i].first] > max(cost, v[cur][i].second)) {
                intensity[v[cur][i].first] = max(cost, v[cur][i].second);
                pq.push({intensity[v[cur][i].first], v[cur][i].first});
            }
        }
    }
    return result;
}
