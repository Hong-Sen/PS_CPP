#include <iostream>
#include <vector>
#define INF 9999999
using namespace std;

int n,m,a,b,c;
int graph[101][101];
vector<int> v[101][101];

void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    vector<int> tmp = v[k][j];
                    v[i][j].clear();
                    v[i][j] = v[i][k];
                    for(int l=1; l<tmp.size(); l++)
                        v[i][j].push_back(tmp[l]);
                }
                    
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
            v[i][j].push_back(i);
            v[i][j].push_back(j);
        }
    }
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        graph[a][b] = min(graph[a][b], c);
    }
    
    floyd();
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
           cout<<graph[i][j]<<" ";
        cout<<"\n";
    }
   
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)    cout<<0<<"\n";
            else{
                cout<<v[i][j].size()<<" ";
                for(int k=0; k<v[i][j].size(); k++){
                    cout<<v[i][j][k]<<" ";
                }
                cout<<"\n";
            }
        }
    }
    
}
