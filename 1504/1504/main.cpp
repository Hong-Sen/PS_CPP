#include <iostream>
#include <queue>
#include <vector>
#define INF 999999
using namespace std;

int n,e,a,b,c,vertex1,vertex2;
vector<pair<int, int>> v[200002];

int dijkstra(int start, int end){
    vector<int> dis(n + 1, INF);
    dis[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({dis[start],start});
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int distance = pq.top().first * -1;
        pq.pop();
        if(dis[cur] > distance)  continue;
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int nextDistance = v[cur][i].second + distance;
            if(dis[next] > nextDistance){
                dis[next] = nextDistance;
                pq.push({nextDistance*-1, next});
            }
        }
        
    }
    return dis[end];
}

int main(){
    cin>>n>>e;
    
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    cin>>vertex1>>vertex2;
    int result1 = 0,result2 = 0;
    bool flag1 = true, flag2 = true;
    //1. 1 -> vertex1 -> vertex2 -> n
    long long start_vtx1 = dijkstra(1, vertex1);
    long long vtx1_vtx2 = dijkstra(vertex1, vertex2);
    long long vtx2_n = dijkstra(vertex2, n);
    if(start_vtx1 >= INF || vtx1_vtx2 >= INF || vtx2_n >= INF)  flag1 = false;
    
    //2. 1 -> vertex2 ->  vertex1 -> n
    long long start_vtx2 = dijkstra(1, vertex2);
    long long vtx2_vtx1 = dijkstra(vertex2, vertex1);
    long long vtx1_n = dijkstra(vertex1, n);
    if(start_vtx2 >= INF || vtx2_vtx1 >= INF || vtx1_n >= INF)  flag2 = false;
    
    if(!flag1 && !flag2)    cout<<"-1";
    else{
        cout<<min(start_vtx1 + vtx1_vtx2 + vtx2_n, start_vtx2 + vtx2_vtx1 + vtx1_n);
    }
    
}
