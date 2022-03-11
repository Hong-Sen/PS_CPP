//
//  main.cpp
//  2644_2
//
//  Created by 홍세은 on 2022/03/11.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m,p1,p2,x,y;
vector<int> v[101];
bool visited[101];
bool flag;

void dfs(int person, int cnt){
    if(person == p2) {
        flag = true;
        cout<<cnt;
        return;
    }
    for(int i=0; i<v[person].size(); i++){
        int next = v[person][i];
        if(!visited[next]){
            visited[person] = true;
            dfs(v[person][i], cnt+1);
        }
    }
}
int main(){
    cin>>n>>p1>>p2>>m;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    visited[p1] = true;
    dfs(p1, 0);
    if(!flag) cout<<"-1";
}
