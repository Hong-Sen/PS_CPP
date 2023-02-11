//
//  main.cpp
//  2637
//
//  Created by 홍세은 on 2023/02/11.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X, Y, K;
bool isMiddle[101];
int degree[101];
vector<pair<int,int>> edge[102];
int result[102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>M;
    for(int i=0; i<M; i++) {
        cin>>X>>Y>>K;
        isMiddle[X] = true;
        degree[Y]++;
        edge[X].push_back({Y,K});
    }
    
    queue<int> q;
    q.push(N);
    result[N] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0; i<edge[now].size(); i++) {
            int next = edge[now][i].first;
            int amount = edge[now][i].second;
            result[next] += result[now] * amount;
            if(--degree[next] == 0) q.push(next);
        }
    }
    
    for(int i=1; i<N; i++) {
        if(!isMiddle[i]) cout<<i<<" "<<result[i]<<"\n";
        
    }
    

}
