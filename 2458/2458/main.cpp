#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int n,m;
int a,b;
int adj[501][501];
int cnt;

void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)    continue;
            adj[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a][b] = 1;
    }
    floyd();

    for(int i=1; i<=n; i++){
        bool flag = true;
        for(int j=1; j<=n; j++){
            if(adj[i][j] == INF && adj[j][i] == INF){
                flag = false;
                break;
            }
            if(adj[i][j] == INF && adj[j][j] != INF){
                flag = true;
            }
        }
        if(flag){
            cnt++;
        }
    }
    cout<<cnt;
}
