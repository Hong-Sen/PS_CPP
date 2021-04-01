#include <iostream>
#include <queue>
#include <vector>
#define INF 99999999
using namespace std;

int n,m,a,b,c;
int graph[101][101];

void floyd(int n){
    for(int mid = 1;  mid<=n; mid++){
        for(int start = 1; start<=n; start++){
            for(int end = 1; end<=n; end++){
                if(graph[start][end] > graph[start][mid] + graph[mid][end])
                    graph[start][end] = graph[start][mid] + graph[mid][end];
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            graph[i][j] = INF;
            if(i==j)    graph[i][j] = 0;
        }
    }
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        graph[a][b] = min(graph[a][b], c);
    }
    
    floyd(n);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j] >= INF)
                cout<<"0 ";
            else
                cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}
