#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[10000];
bool visited[1000];

void dfs(int start){
    visited[start] = true;
    cout<<start<<" ";
    for(int i=0; i<adj[start].size(); i++){
        int next = adj[start][i];
        if(!visited[next])  dfs(next);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int tmp = q.front();
        cout<<tmp<<" ";
        q.pop();
        for(int i=0; i<adj[tmp].size(); i++){
            if(!visited[adj[tmp][i]]){
                q.push(adj[tmp][i]);
                visited[adj[tmp][i]] = true;
            }
        }
    }
}

int main(){
    int n,m,start;
    cin>>n>>m>>start;
    for(int i=0; i<m; i++){
        int v,u;
        cin>>v>>u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(int i=0; i<n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(start);
    cout<<"\n";
    for(int i=0; i<=n; i++){
        visited[i] = false;
    }
    bfs(start);
}
