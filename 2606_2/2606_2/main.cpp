//
//  main.cpp
//  2606_2
//
//  Created by 홍세은 on 2022/03/09.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m,c1,c2;
int cnt;
vector<int> computer[101];
bool visited[101];

void dfs(int x) {
    visited[x] = true;
    for(int i=0; i<computer[x].size(); i++){
        int next = computer[x][i];
        if(!visited[next]){
            dfs(next);
            cnt++;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>c1>>c2;
        computer[c1].push_back(c2);
        computer[c2].push_back(c1);
    }
    dfs(1);
    cout<<cnt;
}
