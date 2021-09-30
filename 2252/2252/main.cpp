#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int A,B;
int edge[32001];
vector<int> adj[32001];
vector<int> result;
queue<int> q;

void topological(){
    while (!q.empty()) {
        int top = q.front();
        result.push_back(top);
        q.pop();
        for(int i=0; i<adj[top].size(); i++){
            int next = adj[top][i];
            edge[next]--;
            if(edge[next] == 0) q.push(next);
        }
    }
}

int main(){
    cin>>n>>m;
    // B->A
    for(int i=0; i<m; i++){
        cin>>A>>B;
        edge[A]++;
        adj[B].push_back(A);
    }

    for(int i=1; i<=n; i++){
        if(edge[i] == 0)    q.push(i);
    }

    topological();
    
    for(int i=result.size()-1; i>=0; i--)
    cout<<result[i]<<" ";
}
