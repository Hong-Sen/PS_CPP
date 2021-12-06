//
//  main.cpp
//  1937
//
//  Created by 홍세은 on 2021/12/06.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int map[501][501];
priority_queue<pair<int, pair<int, int>>> pq;
int dis[501][501];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int result;

void dijkstra(){
    while (!pq.empty()) {
        int cr = pq.top().second.first;
        int cc = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();
        for(int i=0; i<4; i++){
            int nr = cr + dy[i];
            int nc = cc + dx[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && map[nr][nc] > cost){
                dis[cr][cc] = max(dis[cr][cc], dis[nr][nc] + 1);
                result = max(dis[cr][cc], result);
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
            pq.push({map[i][j], {i,j}});
        }
    }
    dijkstra();
    cout<<result + 1;
}
