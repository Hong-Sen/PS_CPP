//
//  main.cpp
//  1389
//
//  Created by 홍세은 on 2022/11/04.
//
// 플로이드 워샬
// 모든 정점간의 최단 거리

#include <iostream>
#define INF 987654321
using namespace std;

int N,M,A,B;
int adj[102][102];
int kevin[102];

int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(i == j) continue;
            adj[i][j] = INF;
        }
    }
    
    for(int i=0; i<M; i++) {
        cin>>A>>B;
        adj[A][B] = 1;
        adj[B][A] = 1;
    }
    
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    
    int sum = INF;
    int result = INF;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            kevin[i] += adj[i][j];
        }
        if(sum > kevin[i]) {
            result = i;
            sum = kevin[i];
        }
    }
    
    cout<<result;
}
