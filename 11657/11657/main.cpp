#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n,m;
int a,b,c;
vector<pair<int, int>> v[505];
long long dist[505];
bool cycle = false;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=2; i<=n; i++)
    dist[i] = INF;
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<v[j].size(); k++){
                int node = v[j][k].first;
                int cost = v[j][k].second;
                if(dist[j] != INF && dist[node] > dist[j] + cost){
                    dist[node] = dist[j] + cost;
                    if(i==n)    cycle = true;
                }
            }
        }
    }
    
    if(cycle)   cout<<"-1";
    else{
        for(int i=2; i<=n; i++){
            if(dist[i] == INF) cout<<"-1\n";
            else cout<<dist[i]<<"\n";
        }
    }
}
