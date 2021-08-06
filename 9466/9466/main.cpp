#include <iostream>
#include <cstring>
using namespace std;

int t,n;
int v[1000001];
bool visited[1000001]; //정점 방문여부
bool done[1000001]; //방문이 끝났는지 확인
int cnt;

void dfs(int node){
    visited[node] = true;
    if(!visited[v[node]])
        dfs(v[node]);
    else if(!done[v[node]]){
        cnt++; //자기자신
        for(int i=v[node]; i!= node; i=v[i]){
            cnt++; //사이클안에 존재하는 정점 수
        }
    }
    done[node] = true;
 }

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
        for(int j=1; j<=n; j++){
            cin>>v[j];
        }
        for(int j=1; j<=n; j++){
            if(visited[j])  continue;
            dfs(j);
        }
        cout<<n - cnt<<"\n";
    }
}
