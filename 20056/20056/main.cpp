#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N,M,K;
int direction[8][2] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};

struct Fireball {
    int r,c;
    long long m,s,d;
    int odd, even;
    int cnt;
};


Fireball board[55][55];
vector<Fireball> v;

void clearBoard() {
    for(int r=1; r<=N; r++) {
        for(int c=1; c<=N; c++) {
            board[r][c].m = 0;
            board[r][c].s = 0;
            board[r][c].d = 0;
            board[r][c].odd = 0;
            board[r][c].even = 0;
            board[r][c].cnt = 0;
        }
    }
}

void move() {
    for(int i=0; i<v.size(); i++) {
        Fireball fb = v[i];
        int r = fb.r;
        int c = fb.c;
        int nr = r + (direction[fb.d][0] * fb.s);
        int nc = c + (direction[fb.d][1] * fb.s);
        
        if(nr > N) nr %= N;
        if(nc > N) nc %= N;
        if(nr < 1) {
            while (nr < 1) {
                nr += N;
            }
        }
        if(nc < 1) {
            while (nc < 1) {
                nc += N;
            }
        }
        
        Fireball nfb = board[nr][nc];
        nfb.m += fb.m;
        nfb.s += fb.s;
        nfb.r = nr;
        nfb.c = nc;
        nfb.d = fb.d;
        if(fb.d % 2 == 1) nfb.odd++;
        else nfb.even++;
        nfb.cnt++;
        board[nr][nc] = nfb;
    }
}

void divide() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            Fireball fb = board[i][j];
            if(fb.cnt == 0) continue;
            if(fb.cnt == 1) {
                v.push_back({fb});
                continue;
            }
            int m = fb.m / 5;
            int s = fb.s / fb.cnt;
            if(m == 0) continue;
            if(fb.odd == 0 || fb.even == 0) {
                v.push_back({i, j, m, s, 0, 0, 0, 0});
                v.push_back({i, j, m, s, 2, 0, 0, 0});
                v.push_back({i, j, m, s, 4, 0, 0, 0});
                v.push_back({i, j, m, s, 6, 0, 0, 0});
            }
            else {
                v.push_back({i, j, m, s, 1, 0, 0, 0});
                v.push_back({i, j, m, s, 3, 0, 0, 0});
                v.push_back({i, j, m, s, 5, 0, 0, 0});
                v.push_back({i, j, m, s, 7, 0, 0, 0});
            }
        }
    }
}

int main(){
    cin>>N>>M>>K;
    int r,c,m,s,d;
    
    for(int i=0; i<M; i++) {
        cin>>r>>c>>m>>s>>d;
        Fireball fb;
        fb.r = r;
        fb.c = c;
        fb.m = m;
        fb.s = s;
        fb.d = d;
        fb.cnt = 1;
        if(d % 2 == 1) fb.odd = 1;
        else fb.even = 1;
        v.push_back(fb);
    }

    while (K--) {
        move();
        v.clear();
        divide();
        clearBoard();
    }
    
    int sum = 0;
    
    for(int i=0; i<v.size(); i++) {
        sum += v[i].m;
    }
    
    cout<<sum;
}
