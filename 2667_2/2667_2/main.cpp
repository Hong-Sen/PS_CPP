//
//  main.cpp
//  2667_2
//
//  Created by 홍세은 on 2022/03/10.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
string s;
int map[26][26];
queue<pair<int, int>> q;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int order,cnt;
priority_queue<int, vector<int>, greater<int>> result;

void dfs(int r, int c){
    map[r][c] = 0;
    cnt++;
    for(int i=0; i<4; i++){
        int nextR = r + dy[i];
        int nextC = c + dx[i];
        if(map[nextR][nextC] == 1) {
            dfs(nextR, nextC);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<n; j++){
            map[i][j] = (int)(s[j] - '0');
            if(map[i][j] == 1) q.push({i,j});
        }
    }
    
    while (!q.empty()) {
        int curR = q.front().first;
        int curC = q.front().second;
        if(map[curR][curC] == 1){
            cnt = 0;
            dfs(curR,curC);
            result.push(cnt);
        }
        q.pop();
    }
    cout<<result.size()<<"\n";
    while (!result.empty()) {
        cout<<result.top()<<"\n";
        result.pop();
    }
    
}
