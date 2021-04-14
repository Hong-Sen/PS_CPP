#include <iostream>
#include <vector>
using namespace std;

int num[110][110];
int visited[110];
int result[110];
int n;
int cnt;
int flag;

void resetVisited(){
    for(int i=0; i<=n; i++)
    visited[i] = 0;
}

void DFS(int a, int b, int x){
    if(flag == 1){
        return;
    }
    
    if(b == x && visited[x] == 1){
        result[x] = x;
        flag = 1;
        cnt++;
        return;
    }
    
    visited[b] = 1;
    
    for(int i=1; i<=n && flag == 0; i++){
        if(num[b][i] == 1 && (i==x || visited[i] == 0)){
            DFS(b, i, x);
        }
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        num[i][x] = 1;
    }
    
    for(int i=1; i<=n; i++){
        resetVisited();
        flag = 0;
        DFS(0, i, i);
    }
    
    cout<<cnt<<"\n";
    for(int i=0; i<=n; i++){
        if(result[i] != 0){
            cout<<result[i]<<"\n";
        }
    }
    
}
