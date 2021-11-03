#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,task;
vector<int> adj[10001];
int edge[10001];
int taskTime[10001];
int result[10001];
queue<int> q;

void topological(){
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0; i<adj[now].size(); i++){
            int next = adj[now][i];
            edge[next]--;
            result[next] = max(taskTime[next]+result[now], result[next]);
            if(edge[next] == 0){
                q.push(next);
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>taskTime[i]>>m;
        edge[i] += m;
        for(int j=0; j<m; j++){
            cin>>task;
            adj[task].push_back(i);
        }
        if(edge[i] == 0){
            q.push(i);
            result[i] = taskTime[i];
        }
    }
    topological();
    sort(result,result+n+1);
    cout<<result[n];
}
