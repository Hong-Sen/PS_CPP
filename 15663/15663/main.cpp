#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n,m;
int arr[9];
bool visited[9];
vector<int> result;
map<vector<int>, int> mp;

void dfs(int cnt){
    if(cnt == m){
        mp.insert({result, 1});
        return;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            result[cnt] = arr[i];
            visited[i] = true;
            dfs(cnt+1);
            visited[i] = false;
        }
    }
}

int main(){
    for(int i=0; i<9; i++)
        result.push_back(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    dfs(0);
    for(auto it=mp.begin(); it!= mp.end(); it++){
        for(int i=0; i<m; i++){
            cout<<it->first[i]<<" ";
        }
        cout<<"\n";
    }
}
