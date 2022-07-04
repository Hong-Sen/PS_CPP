#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[11][11];
bool isVisited[11][11][11][11];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상,하,좌,우
int result;
bool flag;

struct Ball {
    int rr, rc, br, bc, cnt;
};

queue<Ball> q;

void bfs(){
    while (!q.empty()) {
        int rr = q.front().rr;
        int rc = q.front().rc;
        int br = q.front().br;
        int bc = q.front().bc;
        int cnt = q.front().cnt;
        q.pop();
        
        cout<<cnt<<"\n";
        cout<<rr<<","<<rc<<"\n"<<br<<","<<bc<<" **\n";
        if(cnt > 10) break;
        if(map[rr][rc] == 'O') {
            flag = true;
            result = cnt;
            break;
        }
    
        isVisited[rr][rc][br][bc] = true;
        
        for(int i=0; i<4; i++) {
            int nrr = rr;
            int nrc = rc;
            int nbr = br;
            int nbc = bc;
            while(1) {
                if(map[nrr + dir[i][0]][nrc + dir[i][1]] == 'O') {
                    nrr += dir[i][0];
                    nrc += dir[i][1];
                    break;
                }
                if(map[nrr + dir[i][0]][nrc + dir[i][1]] != '#') {
                    nrr += dir[i][0];
                    nrc += dir[i][1];
                }
                else break;
            }
            
            while(1) {
                if(map[nbr + dir[i][0]][nbc + dir[i][1]] == 'O') {
                    nbr += dir[i][0];
                    nbc += dir[i][1];
                    break;
                }
                else if(map[nbr + dir[i][0]][nbc + dir[i][1]] != '#') {
                    nbr += dir[i][0];
                    nbc += dir[i][1];
                }
                else break;
            }
            
            // 파란 구슬이 구멍에 빠진 경우
            if(map[nbr][nbc] == 'O') {
                continue;
            }
            
            // 구슬이 겹친 경우
            if(nrr == nbr && nrc == nbc) {
                switch (i) {
                    case 0: // 상
                        if(rr < br) nbr++;
                        else nrr++;
                        break;
                        
                    case 1: // 하
                        if(rr > br) nbr--;
                        else nrr--;
                        break;
                        
                    case 2: // 좌
                        if(rc < bc) nbc++;
                        else nrc++;
                        break;
                        
                    case 3: // 우
                        if(rc > bc) nbc--;
                        else nrc--;
                        break;
                    default:
                        break;
                }
            }
            
            if(!isVisited[nrr][nrc][nbr][nbc]) q.push({nrr,nrc,nbr,nbc, cnt+1});
        }
        
    }
    
}
int main(){
    int rr, rc, br, bc;
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>map[i][j];
            if(map[i][j] == 'R') {
                rr = i;
                rc = j;
            }
            if(map[i][j] == 'B') {
                br = i;
                bc = j;
            }
        }
    }
    q.push({rr,rc,br,bc,0});
    
    bfs();
    
    if(flag) cout<<result;
    else cout<<"-1";
    
}
