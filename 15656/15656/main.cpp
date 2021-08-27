#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int n,m;
int arr[MAX];
int result[MAX];

void dfs(int index){
    if(index == m){
        for(int i=0; i<m; i++)
            cout<<result[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0; i<n; i++){
        result[index] = arr[i];
        dfs(index+1);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr,arr+n);
    dfs(0);
}
