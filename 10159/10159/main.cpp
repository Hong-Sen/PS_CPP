//
//  main.cpp
//  10159
//
//  Created by 홍세은 on 2022/07/06.
//

#include <iostream>
#define INF 987654321
using namespace std;

int N,M;
int measuredItem[101][101];

int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            measuredItem[i][j] = INF;
            if(i==j) measuredItem[i][j] = 0;
        }
    }
    for(int i=0; i<M; i++) {
        int a,b;
        cin>>a>>b;
        measuredItem[a][b] = 1;
    }
    
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                measuredItem[i][j] = min(measuredItem[i][j], measuredItem[i][k] + measuredItem[k][j]);
            }
        }
    }
    
    for(int i=1; i<=N; i++) {
        int cnt = 0;
        for(int j=1; j<=N; j++) {
            if(measuredItem[i][j] >= INF) {
                if(measuredItem[j][i] == INF) cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    
}
