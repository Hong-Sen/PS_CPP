#include <iostream>
#define INF 9999999
using namespace std;

int graph[401][401];

void floyd(int n){
    for(int mid = 1; mid <=n; mid++){
        for(int start = 1; start<=n; start++){
            for(int end = 1; end<=n; end++){
                if(graph[start][end] > graph[start][mid] + graph[mid][end])
                    graph[start][end] = graph[start][mid] + graph[mid][end];
            }
        }
    }
}

int main(){
    int v,e,a,b,c;
    cin>>v>>e;
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            graph[i][j] = INF;
            if(i==j)    graph[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        graph[a][b] = c;
    }
    
    floyd(v);
   int result = INF;
    
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(i != j){
                result = min(graph[i][j] + graph[j][i], result);
            }
            
        }
    }
    if(result == INF)    cout<<"-1";
    else    cout<<result;
    
}
