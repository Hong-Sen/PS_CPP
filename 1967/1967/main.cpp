#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v[10001];
bool visited[10001];
int n;
int tmp;
int result;

void resetVisited(){
    for(int i=0; i<=n; i++)
        visited[i] = false;
}
void dfs(int start, int dis){
    visited[start] = true;
    if(tmp < dis){
        tmp = dis;
    }
    for(int i=0; i<v[start].size(); i++){
        int next = v[start][i].first;
        if(!visited[next]){
            dfs(next, dis + v[start][i].second);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n-1; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    for(int i=1; i<=n; i++){
        if(!v[i].empty()){
            tmp = 0;
            resetVisited();
           dfs(i,0);
            result = max(result,tmp);
        }
    }
    cout<<result;
}
