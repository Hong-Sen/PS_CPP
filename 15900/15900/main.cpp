#include <iostream>
#include <vector>
using namespace std;

int n;
int a,b;
vector<int> tree[500001];
bool visited[500001];
int sum;

void dfs(int x, int cnt){
    bool flag = false;
    for(int i=0; i<tree[x].size(); i++){
        if(!visited[tree[x][i]]){
            flag = true;
            visited[tree[x][i]] = true;
            dfs(tree[x][i], cnt+1);
            visited[tree[x][i]] = false;
        }
    }
    if(!flag){
        sum += cnt;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    visited[1] = true;
    dfs(1, 0);
    if(sum %2 == 0) cout<<"No";
    else cout<<"Yes";
}
