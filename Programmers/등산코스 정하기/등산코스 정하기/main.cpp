#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool isSummit[50001];
int intensity[50001];
vector<pair<int,int>> v[50001];
priority_queue<pair<int,int>> pq; // {intensity, gate}
int resultIntensity = 10000001;
int resultSummit = 0;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for(auto p: paths) {
        v[p[0]].push_back({p[1], p[2]});
        v[p[1]].push_back({p[0], p[2]});
    }
    
    // 최소의 intensity를 구해야 하므로 max 값보다 큰 10000001로 초기화
    for(int i=1; i<=n; i++) intensity[i] = 10000001;
    
    // 산봉우리면 true
    for(int i: summits) {
        isSummit[i] = true;
    }
    
    for(int i: gates) {
        intensity[i] = -1; // 다른 출입구로 이동하는 것 방지
        pq.push({0,i});
    }
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost > resultIntensity) continue; // min intensity를 구하는 것이므로
        if(isSummit[cur]) {
            if(resultIntensity > cost) {
                resultIntensity = cost;
                resultSummit = cur;
            }
            else if(resultIntensity == cost && resultSummit > cur) {
                resultSummit = cur;
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
    return {resultSummit, resultIntensity};
}
