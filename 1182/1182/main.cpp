#include <iostream>
using namespace std;

int n,s;
int arr[1000001];
int cnt;

void dfs(int index, int sum){
    sum += arr[index];
    if(index >= n)
        return;
    if(sum == s)
        cnt++;
    dfs(index+1, sum - arr[index]);
    dfs(index+1, sum);
}


int main(){
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    dfs(0,0);
    cout<<cnt;
    
}
