#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool isVisited[101][101];

int bfs(vector<vector<int> > maps) {
    int cnt = 10001;
    queue<pair<pair<int,int>, int>> q; // {{r,c},cost}
    q.push({{0,0},1});
    isVisited[0][0] = true;
    while(!q.empty()) {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        
        if(curR == n-1 && curC == m-1){
            cnt = cost;
        }
        
        for(int i=0; i<4; i++) {
            int nextR = curR + dy[i];
            int nextC = curC + dx[i];
            
            if(nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) continue;
            if(isVisited[nextR][nextC] || maps[nextR][nextC] == 0) continue;
            
            isVisited[nextR][nextC] = true;
            q.push({{nextR, nextC}, cost+1});
        }
    }
    
    if(cnt == 10001) cnt = -1;
    return cnt;
}

int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    return bfs(maps);
}
