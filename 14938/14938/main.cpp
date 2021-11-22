#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321
using namespace std;

int n,m,r,t,a,b,l;
int item[101];
vector<pair<int, int>> v[101];
int dist[101];
bool visited[101];
int result;

void resetDist(){
    for(int i=1; i<=n; i++)
        dist[i] = INF;
}
void collect(int start){
    resetDist();
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({start, 0});
    dist[start] = 0;
    visited[start] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int nextCost = v[cur][i].second + cost;
            if(dist[next] < nextCost)   continue;
            if(nextCost <= m){
                dist[next] = nextCost;
                q.push({next, nextCost});
                visited[next] = true;
            }
        }
    }
}

int main(){
    cin>>n>>m>>r;
    for(int i=1; i<=n; i++){
        cin>>t;
        item[i] = t;
    }
    for(int i=0; i<r; i++){
        cin>>a>>b>>l;
        v[a].push_back({b,l});
        v[b].push_back({a,l});
    }
    for(int i=1; i<=n; i++){
        collect(i);
        int sum = 0;
        for(int i=1; i<=n; i++){
            if(visited[i])  sum += item[i];
        }
        result = max(result, sum);
    }
    cout<<result;
}
