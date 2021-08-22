#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int n,m;
int arr[MAX];
int result[MAX];

void dfs(int cnt, int index){
    if(cnt == m){
        for(int i=0; i<m; i++)
        cout<<result[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=index; i<n; i++){
        result[cnt] = arr[i];
        dfs(cnt+1, i+1);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    dfs(0,0);
    
}
