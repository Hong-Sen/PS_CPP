#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int t;
int n = 1;
int arr[126][126];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int dist[126][126];

bool isInside(int row, int col){
    if(row>=0 && row<n && col>=0 && col<n)  return true;
    else return false;
}

void dijkstra(){
    dist[0][0] = arr[0][0];
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({-dist[0][0],{0,0}});
    while (!q.empty()) {
        int cr = q.top().second.first;
        int cc = q.top().second.second;
        q.pop();
        for(int i=0; i<4; i++){
            int nr = cr + dy[i];
            int nc = cc + dx[i];
            if(isInside(nr, nc)){
                if(dist[nr][nc] <= dist[cr][cc] + arr[nr][nc])   continue;
                dist[nr][nc] = dist[cr][cc] + arr[nr][nc];
                q.push({-dist[nr][nc],{nr,nc}});
            }
        }
    }
}

int main(){
    while (1) {
        cin>>n;
        if(n==0)    break;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = INF;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }
        dijkstra();
        cout<<"Problem "<<++t<<": "<<dist[n-1][n-1]<<"\n";
    }
}
