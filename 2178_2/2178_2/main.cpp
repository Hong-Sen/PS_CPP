#include <iostream>
#include <string>
#include <queue>
#define INF 9999
using namespace std;

int N,M;
string s;
char map[101][101];
int dis[101][101];
queue<pair<int, int>> q;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs() {
    q.push({0,0});
    map[0][0] = '0';
    dis[0][0] = 1;
    while (!q.empty()) {
        int curC = q.front().first;
        int curR = q.front().second;
        q.pop();
        if(curC == N-1 && curR ==M-1){
            break;
        }
        for(int i=0; i<4; i++){
            int nextC = curC + dy[i];
            int nextR = curR + dx[i];
            if(nextC >=0 && nextC <N && nextR >= 0 && nextR <M && map[nextC][nextR] == '1'){
                map[nextC][nextR] = '0';
                dis[nextC][nextR] = dis[curC][curR] + 1;
                q.push({nextC, nextR});
            }
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>s;
        for(int j=0; j<s.length(); j++){
            map[i][j] = s[j];
            dis[i][j] = INF;
        }
    }
    bfs();
    cout<<dis[N-1][M-1];
}
