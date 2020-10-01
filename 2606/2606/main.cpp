#include <iostream>
#include <vector>
using  namespace std;

int n,m;
int arr[101][101];
int visited[101];
int cnt;

int virus(int k){
    visited[k] = 1;
    cnt++;
    for(int i=1;i<=n; i++){
        if(arr[k][i] == 1 && visited[i] != 1)
            virus(i);
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    virus(1);
    cout<< cnt-1 <<"\n";
    
}
