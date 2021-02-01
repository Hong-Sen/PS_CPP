#include <iostream>
using namespace std;

int n,m;
int arr[9];
bool visited[9];

void dfs(int c){
    if(c==m){
        for(int i=0; i<m; i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
    }
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            arr[c] = i;
            visited[i] = true;
            dfs(c+1);
            visited[i] = false;
        }
        
    }
}

int main(){
    cin>>n>>m;
    dfs(0);
    return 0;
}
