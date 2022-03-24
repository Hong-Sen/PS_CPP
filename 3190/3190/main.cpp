#include <iostream>
#include <queue>
using namespace std;

int N,K,L;
int map[101][101];
queue<pair<int, char>> spin;
queue<pair<int, int>> q;
int direction[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}}; // {E,N,W,S}

bool isInside(int r, int c){
    return r>=0 && r<N && c>=0 && c<N;
}

int main(){
    cin>>N>>K;
    int x,y;
    for(int i=0; i<K; i++){
        cin>>y>>x;
        map[y-1][x-1] = 1;
    }
    cin>>L;
    int t;
    char spinDir;
    for(int i=0; i<L; i++){
        cin>>t>>spinDir;
        spin.push({t,spinDir});
    }
    
    int now = 0, r = 0, c = 0, dir = 0;
    int snake[101][101] = {0,};
    q.push({0,0});
    while (1) {
        // 종료 조건
        if(!isInside(r, c) || snake[r][c] == 1) break;
        // 사과 X -> 꼬리 이동
        if(map[r][c] == 0){
            snake[q.front().first][q.front().second] = 0;
            q.pop();
        }
        // 머리 이동
        snake[r][c] = 1;
        q.push({r,c});
        
//        cout<<"\n";
//        for(int i=0; i<N; i++){
//            for(int j=0; j<N; j++){
//                cout<<snake[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
        
        // 전진
        r += direction[dir][0];
        c += direction[dir][1];
        now++;
        
        if(now == spin.front().first){
            cout<<now<<" "<<spin.front().second<<"\n";
            if(spin.front().second == 'L') {
                dir = (dir+1) % 4;
            }
            else {
                dir = dir - 1 < 0 ? 3 : dir - 1;
            }
            spin.pop();
        }
    }
    cout<<now;
}
