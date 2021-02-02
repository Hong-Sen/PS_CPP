#include <iostream>
using namespace std;

int n,m;
int arr[9];
int visited[9];

void dfs(int cnt,int index) {
    if(cnt==m){
        for(int i=0; i<m; i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
    }
    for(int i=index; i<=n; i++){
        if(!visited[i]){
            arr[cnt] = i;
            visited[i] = true;
            dfs(cnt+1,i+1);
            visited[i] = false;
        }
        
    }
}
int main(){
    cin>>n>>m;
    dfs(0,1);
}
