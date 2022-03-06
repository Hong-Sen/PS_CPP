//
//  main.cpp
//  1260_2
//
//  Created by 홍세은 on 2022/03/07.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m,v;
int v1,v2;
vector<int> graph[1001];
bool visited[1001];

void dfs(int x){
    cout<<x<<" ";
    visited[x] = true;
    
    for(int i=0; i<graph[x].size(); i++){
        int next = graph[x][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        cout<<cur<<" ";
        q.pop();
        for(int i=0; i<graph[cur].size(); i++){
            int next = graph[cur][i];
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(){
    cin>>n>>m>>v;
    for(int i=0; i<m; i++){
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs(v);
    
    cout<<"\n";
    memset(visited, false, sizeof(visited));
    
    bfs(v);
}
