// 31.41m
#include <iostream>
using namespace std;

int N,N2;
int map[999][999];
int result[2];

void solution() {
    int r = N/2;
    int c = N/2;
    int dir = 0;
    int num = 1;
    int cnt = 1;
    map[r][c] = num;
    
    while (num < N * N) {
        if(dir == 0) {
            for(int i=0; i<cnt; i++) {
                map[--r][c] = ++num;
                if(num == N*N) break;
            }
        }
        else if(dir == 1) {
            for(int i=0; i<cnt; i++) {
                map[r][++c] = ++num;
            }
            cnt++;
        }
        else if(dir == 2) {
            for(int i=0; i<cnt; i++) {
                map[++r][c] = ++num;
            }
        }
        else {
            for(int i=0; i<cnt; i++) {
                map[r][--c] = ++num;
            }
            cnt++;
        }
        dir = (dir + 1) % 4;
    }
}


int main() {
    cin>>N>>N2;
    
    solution();
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout<<map[i][j]<<" ";
            if(map[i][j] == N2) {
                result[0] = i+1;
                result[1] = j+1;
            }
        }
        cout<<"\n";
    }
    
    cout<<result[0]<<" "<<result[1];
}
