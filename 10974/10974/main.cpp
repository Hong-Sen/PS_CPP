#include <iostream>
using namespace std;

int n;
int arr[8];
bool visited[8];

void dfs(int cnt){
    if(cnt == n){
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            dfs(cnt+1);
            visited[i] = false;
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
}
