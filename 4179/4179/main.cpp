#include <iostream>
#include <queue>
#define INF 1000002
using namespace std;

int R,C;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
char map[1001][1001];
int fireVisited[1001][1001];
int manVisited[1001][1001];
queue<pair<int,int>> fireQ;
queue<pair<int,int>> manQ;
int result = INF;

int main() {
    cin>>R>>C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin>>map[i][j];
            fireVisited[i][j] = INF;
            manVisited[i][j] = INF;
            if(map[i][j] == 'F') {
                fireVisited[i][j] = 0;
                fireQ.push({i,j});
            }
            if(map[i][j] == 'J') {
                manVisited[i][j] = 0;
                manQ.push({i,j});
            }
        }
    }
    
    while(!fireQ.empty()) {
        int r = fireQ.front().first;
        int c = fireQ.front().second;
        fireQ.pop();
        for(int i=0; i<4; i++) {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if(nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if(map[nr][nc] == '#') continue;
                if(fireVisited[nr][nc] > fireVisited[r][c] + 1) {
                    fireVisited[nr][nc] = fireVisited[r][c] + 1;
                    fireQ.push({nr,nc});
                }
            }
        }
    }
    
    while (!manQ.empty()) {
        int r = manQ.front().first;
        int c = manQ.front().second;
        int time = manVisited[r][c];
        manQ.pop();
        for(int i=0; i<4; i++) {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if(nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if(map[nr][nc] == '#' || fireVisited[nr][nc] <= time + 1) continue;
                if(manVisited[nr][nc] > time + 1) {
                    manVisited[nr][nc] = time + 1;
                    manQ.push({nr, nc});
                }
            }
            else {
                result = min(result, time + 1);
            }
        }
    }
    
    
//    for(int i=0; i<R; i++) {
//        for(int j=0; j<C; j++) {
//            cout<<fireVisited[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//    cout<<"\n";
//
//    for(int i=0; i<R; i++) {
//        for(int j=0; j<C; j++) {
//            cout<<manVisited[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//
    result == INF ? cout<<"IMPOSSIBLE" : cout<<result;
}
