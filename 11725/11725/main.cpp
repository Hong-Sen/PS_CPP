#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int result[100002];
bool visited[100002];
int n;

void dfs(int k){
    visited[k] = true;
    for(int i=0; i<v[k].size(); i++){
        int next = v[k][i];
        if(!visited[next]){
            result[next] = k;
            dfs(next);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v2;
    for(int i=0; i<=n; i++){
        v.push_back(v2);
    }
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(1);
    
    for(int i=2; i<=n; i++)
    cout<<result[i]<<"\n";
}
