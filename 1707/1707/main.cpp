#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[20002];
int visited[20002];
int k,v,e,a,b;

void resetArray(){
    for(int i=0; i<=v+1; i++){
        arr[i].clear();
        visited[i] = 0;
    }
}

void dfs(int n){
    if(visited[n] == 0) visited[n] = 1;
    for(int i=0; i<arr[n].size(); i++){
        int next = arr[n][i];
        if(visited[next] == 0){
            if(visited[n] == 1) visited[next] = 2;
            else if(visited[n] == 2)    visited[next] = 1;
            dfs(next);
        }
    }
}

bool bipartiteGraph(vector<int> arr[]){
    for(int i=1; i<=v; i++){
        for(int j=0; j<arr[i].size(); j++){
            int next = arr[i][j];
            if(visited[i] == visited[next]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>v>>e;
        resetArray();
        for(int j=0; j<e; j++){
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(int i=1; i<=v; i++){
            if(visited[i] == 0) dfs(i);
        }
        if(bipartiteGraph(arr)) cout<<"YES\n";
        else    cout<<"NO\n";
    }
}
