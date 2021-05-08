#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n,m,cnt,k;
bool visited[1001]; //정점 방문여부

bool DFS(int cur, int before, vector<int> tree[]){
    visited[cur] = true;
    for(auto i : tree[cur]){
        if(i == before) continue;
        if(visited[i])    return false;
        if(!DFS(i, cur, tree))    return false;
    }
    return true;
}

int main(){
    while (1) {
        cin>>n>>m;
        if(n==0 && m==0)    break;
        memset(visited, false, sizeof(visited));
        vector<int> tree[1001];
        cnt = 0;
        for(int i=0; i<m; i++){
            int v,w;
            cin>>v>>w;
            tree[v].push_back(w);
            tree[w].push_back(v);
        }
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                if(DFS(i, 0, tree))   cnt++;
            }
        }
        cout << "Case " << ++k<<": ";
        if (cnt == 0) cout << "No trees.";
        else if (cnt == 1) cout << "There is one tree.";
        else cout << "A forest of " << cnt << " trees.";
        cout << "\n";
    }
}
