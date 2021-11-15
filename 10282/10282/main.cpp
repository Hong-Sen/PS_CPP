#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int t,n,d,c;
int a,b,s;
int cnt;
int last;
vector<pair<int, int>> v[10001];
int dist[10001];

void dijkstra(int com){
    queue<int> q;
    q.push(com);
    dist[com] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int cost = v[cur][i].second;
            if(dist[next] > dist[cur] + cost){
                dist[next] = dist[cur] + cost;
                q.push(next);
            }
        }
    }
    for(int i=0; i<=n; i++){
        if(dist[i] != INF){
            cnt++;
            last = max(last, dist[i]);
        }
    }
}

int main(){
    cin>>t;
    while (t--) {
        cin>>n>>d>>c;
        cnt = last =0;
        
        for(int i=0; i<=n; i++){
            dist[i] = INF;
            v[i].clear();
        }
        
        for(int i=0; i<d; i++){
            cin>>a>>b>>s;
            v[b].push_back({a,s});
        }
        dijkstra(c);
        cout<<cnt<<" "<<last<<"\n";
    }
}
