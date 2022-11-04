//
//  main.cpp
//  6497
//
//  Created by 홍세은 on 2022/11/04.
//

// 크루스칼 알고리즘(최소 스패닝 트리)
// 가중치, 양방향, 모든 노드 연결, 최소 비용

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int m,n,a,b,c;
int parent[200001];
int sum, result;
vector<pair<int, pair<int, int>>> v;

int findParent(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = findParent(parent[x]);
}

bool isSameParent(int x, int y) {
    if(findParent(x) == findParent(y)) return true;
    else return false;
}

void unionFind(int x, int y){
    int p1 = findParent(x);
    int p2 = findParent(y);
    parent[p2] = p1;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    while (1) {
        cin>>m>>n;
        if(m == 0 && n == 0) break;
        sum = 0;
        result = 0;
        v.clear();
        memset(parent, 0, sizeof(parent));
        
        for(int i=0; i<n; i++) {
            cin>>a>>b>>c;
            v.push_back({c,{a,b}});
            sum += c;
        }
        
        sort(v.begin(), v.end());
        
        for(int i=0; i<m; i++) {
            parent[i] = i;
        }
        
        for(int i=0; i<v.size(); i++) {
            int x = v[i].second.first;
            int y = v[i].second.second;
            int cost = v[i].first;
            if(!isSameParent(x, y)) {
                unionFind(x, y);
                result += cost;
            }
        }
        cout<<sum - result<<"\n";
    }
}
