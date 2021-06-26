#include <iostream>
#include <algorithm>
#include <vector>
#define INF 100001
using namespace std;

int n,m,a,b,c;
int bus[101][101];
vector<int> path[101][101]; //경로

void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(bus[i][k] + bus[k][j] < bus[i][j]){
                    bus[i][j] = bus[i][k] + bus[k][j];
                    path[i][j].clear();
                    for(int l=0; l<path[i][k].size(); l++)
                        path[i][j].push_back(path[i][k][l]);
                    for(int l=1; l<path[k][j].size(); l++)
                        path[i][j].push_back(path[k][j][l]);
                    
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)    bus[i][j] = 0;
            else    bus[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        if(bus[a][b] > c){
            bus[a][b] = c;
            path[a][b].clear();
            path[a][b].push_back(a);
            path[a][b].push_back(b);
        }
    }
    
   floyd();
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(bus[i][j] == INF)    cout<<0<<" ";
            else    cout<<bus[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<path[i][j].size()<<" ";
            for(int k=0; k<path[i][j].size(); k++){
                cout<<path[i][j][k]<<" ";
            }
            cout<<"\n";
        }
    }
}
