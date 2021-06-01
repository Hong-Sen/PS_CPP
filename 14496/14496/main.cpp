#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int a,b,n,m;
vector<int> v[10001];
int dist[1001];

void bfs(){
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if(x == b){
            cout<<dist[x];
            return;
        }
        for(int i=0; i<v[x].size(); i++){
            int next = v[x][i];
            if(dist[next] == -1){
                q.push(next);
                dist[next] = dist[x] + 1;
            }
        }
    }
    cout<<"-1";
}

int main(){
    cin>>a>>b>>n>>m;
    memset(dist, -1, sizeof(dist)); //string.h
    for(int i=0; i<m; i++){
        int c,d;
        cin>>c>>d;
        v[c].push_back(d);
        v[d].push_back(c);
    }
    bfs();
}
