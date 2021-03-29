#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 99999999
using namespace std;

int dis[1001];
vector<pair<int, int>> v[100001];

void dijkstra(int start){
    dis[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(dis[start], start));
    
    while(!pq.empty()){
        int cur = pq.top().second; //정점
        int distance = pq.top().first * -1; //pq는 maxHeap배열이므로 -1를 곱해서 가장 작은 가중치가 맨앞으로 가게한다.
        pq.pop();
        if(dis[cur] < distance)     continue;
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int nextDistance = distance + v[cur][i].second;
            
            if(nextDistance < dis[next]){
                dis[next] = nextDistance;
                pq.push(make_pair(nextDistance * -1, next));
            }
        }
        
    }
}

int main(){
    int n,m,start,end;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        dis[i] = INF;
    }
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c; //a=출발도시 , b=도착도시, c=버스비용
        v[a].push_back(make_pair(b, c));
    }
    
    cin>>start>>end;
    
    dijkstra(start);
    cout<<dis[end];
 
}
