#include <iostream>
using namespace std;

int n,m;
int arr[1001][1001];
int visited[1001];

void dfs(int x){
    visited[x] = 1;
    for(int i=1; i<=n; i++){
        if(arr[x][i] == 1 && visited[i] == 0){
            dfs(i);
        }
        
    }
    
}

int main(){
    
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    int cnt = 0;
    //간선이 없는 노드들도 갯수를 세어주어야 한다!
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            cnt++;
            dfs(i);
        }
  
    }
    cout<<cnt<<"\n";
}
