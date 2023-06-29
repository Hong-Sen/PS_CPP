#include <iostream>
#include <vector>
using namespace std;

int N,M,a,b;
vector<int> friends[2001];
bool visited[2001];
bool result;

void dfs(int n, int cnt) {
    if(cnt == 4) {
        result = true;
        return;
    }
    visited[n] = true;
    
    for(int i=0; i<friends[n].size(); i++) {
        int next = friends[n][i];
        if(!result && !visited[next]) {
            dfs(next, cnt+1);
        }
    }
    visited[n] =false;
}

int main() {
    cin>>N>>M;
    for(int i=0; i<M; i++) {
        cin>>a>>b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    
    for(int i=0; i<N; i++) {
        dfs(i, 0);
        if(result) break;
    }
    cout<<result;
}
