#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> connect[201];
int network[201];
int cnt;

void bfs(int x) {
    queue<int> q;
    q.push(x);
    network[x] = cnt;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<connect[cur].size(); i++) {
            int next = connect[cur][i];
            if(network[next] == 0) {
                network[next] = cnt;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0; i<computers.size(); i++) {
        for(int j=0; j<computers[i].size(); j++) {
            if(i == j) continue;
            if(computers[i][j] == 1) connect[i].push_back(j);
        }
    }
    
    for(int i=0; i<n; i++) {
        if(network[i] == 0) {
            cnt++;
            bfs(i);
        }
    }

    return cnt;
}
