//
//  main.cpp
//  14890
//
//  Created by 홍세은 on 2022/09/02.
//

#include <iostream>
#include <cmath>
using namespace std;

int N,L;
int map[101][101];
int cnt;

void isPossible(int r, int c) {
    // 가로
    int ramp[101] = {0,};
    int prev = 0;
    bool flag = true;
    for(int i=1; i<N; i++) {
        if(!flag) break;
        prev = map[r][i-1];
        if(map[r][i] == prev) continue;
        if(abs(map[r][i] - prev) != 1) {
            flag = false;
            break;
        }
        else {
            if(prev - map[r][i] == 1) { // 높 --> 낮
                if(i + L > N) {
                    flag = false;
                    break;
                }
                // 경사로 놓을 칸 높이 비교
                for(int idx = i; idx<i+L; idx++) {
                    if(map[r][i] != map[r][idx] || ramp[idx] >= 1) {
                        flag = false;
                        break;
                    }
                    ramp[idx]++;
                }
            }
            else { // 낮 --> 높
                if(i - L < 0) {
                    flag = false;
                    break;
                }
                // 경사로 놓을 칸 높이 비교
                for(int idx = i-1; idx >= i-L; idx--) {
                    if(map[r][i-1] != map[r][idx] || ramp[idx] >= 1) {
                        flag = false;
                        break;
                    }
                    ramp[idx]++;
                }
            }
        }
    }
    
    if(flag) cnt++;
    
    // 세로
    int ramp2[101] = {0,};
    prev = 0;
    flag = true;
    for(int i=1; i<N; i++) {
        if(!flag) break;
        prev = map[i-1][c];
        if(map[i][c] == prev) continue;
        if(abs(map[i][c] - prev) != 1) {
            flag = false;
            break;
        }
        else {
            if(prev - map[i][c] == 1) { // 높 --> 낮
                if(i + L > N) {
                    flag = false;
                    break;
                }
                // 경사로 놓을 칸 높이 비교
                for(int idx = i; idx<i+L; idx++) {
                    if(map[i][c] != map[idx][c] || ramp2[idx] >= 1) {
                        flag = false;
                        break;
                    }
                    ramp2[idx]++;
                }
            }
            else { // 낮 --> 높
                if(i - L < 0) {
                    flag = false;
                    break;
                }
                // 경사로 놓을 칸 높이 비교
                for(int idx = i-1; idx >= i-L; idx--) {
                    if(map[i-1][c] != map[idx][c] || ramp2[idx] >= 1) {
                        flag = false;
                        break;
                    }
                    ramp2[idx]++;
                }
            }
        }
    }
    if(flag) cnt++;

}

int main(){
    cin>>N>>L;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<N; i++) {
        isPossible(i, i);
    }
    
    cout<<cnt;
}
