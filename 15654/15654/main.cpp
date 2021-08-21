#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
bool visited[10];
int result[10];
int n,m;

void dfs(int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            result[cnt] = arr[i];
            dfs(cnt+1);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr,arr+n);
    dfs(0);
}
