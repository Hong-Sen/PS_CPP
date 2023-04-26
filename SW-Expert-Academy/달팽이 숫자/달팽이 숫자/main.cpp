#include <iostream>
#include <cstring>
using namespace std;

int T,N,idx;
int map[11][11];
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // 우하좌상

int main() {
    cin>>T;
    while (T--) {
        cin>>N;
        memset(map,0,sizeof(map));
        map[0][0] = 1;
        int r = 0, c = 0, n = 2, d = 0;
        while(n <= N*N) {
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];
            if(nr < 0 || nr >= N || nc < 0 || nc >=N || map[nr][nc] != 0) {
                d  = (d + 1) % 4;
                continue;
            }
            r = nr, c = nc;
            map[nr][nc] = n;
            n++;
        }
        cout<<"#"<<++idx<<"\n";
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cout<<map[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
