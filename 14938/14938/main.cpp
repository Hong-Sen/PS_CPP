//
//  main.cpp
//  14938
//
//  Created by 홍세은 on 2022/07/05.
//

#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n,m,r;
int item[101];
int adj[101][101];
int dis[101][101];
int result;

int main(){
    cin>>n>>m>>r;
    for(int i=0; i<n; i++) {
        cin>>item[i];
    }
    
    int a,b,l;
    for(int i=0; i<r; i++) {
        cin>>a>>b>>l;
        adj[a-1][b-1] = l;
        adj[b-1][a-1] = l;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(adj[i][j] == 0) adj[i][j] = INF;
            if(i==j) adj[i][j] = 0;
        }
    }
    
    // 각 정점끼리 최단 거리 구하기
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    
    // 최대 아이템수 구하기
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=0; j<n; j++) {
            if(adj[i][j] <= m) sum += item[j];

        }
        result = max(result, sum);
    }
    cout<<result;
}
