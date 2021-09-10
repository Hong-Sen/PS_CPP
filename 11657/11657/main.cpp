#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

struct triple{
    int to,from,cost;
};

int n,m;
int a,b,c;
vector<triple> edge;
long long dist[505];
bool cycle;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=2; i<=n; i++)
    dist[i] = INF;
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        triple tmp;
        tmp.from = a;
        tmp.to = b;
        tmp.cost = c;
        edge.push_back(tmp);
    }
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<edge.size(); j++){
            int from = edge[j].from;
            int to = edge[j].to;
            int cost = edge[j].cost;
            if(dist[from] == INF)   continue;
            if(dist[to] > dist[from] + cost)    dist[to] = dist[from] + cost;
        }
    }
    
    for(int i=0; i<edge.size(); i++){
        int from = edge[i].from;
        int to = edge[i].to;
        int cost = edge[i].cost;
        
        if(dist[from] == INF)   continue;
        if(dist[to] > dist[from] + cost){
            cycle = true; //음의 사이클
        }
    }
    
    if(cycle)   cout<<"-1";
    else{
        for(int i=2; i<=n; i++){
            if(dist[i] == INF)  cout<<"-1\n";
            else cout<<dist[i]<<"\n";
        }
    }
}
