//
//  main.cpp
//  1347
//
//  Created by 홍세은 on 2022/07/29.
//

#include <iostream>
using namespace std;

int n;
string s;
char map[101][101];
int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
int curR = 50, curC = 50, d = 0;
int minR = 101, minC = 101, maxR = 0, maxC = 0;

int main(){
    cin>>n>>s;
    
    int curR = 50, curC = 50;
    map[curR][curC] = '.';
    int d = 0;
    for(char c: s) {
        if(c == 'R') {
            d = (d + 1) % 4;
        }
        else if(c == 'L') {
            d = (d - 1);
            if(d < 0) d += 4;
        }
        else {
            curR += dir[d][0];
            curC += dir[d][1];
            map[curR][curC] = '.';
        }
    }
    
    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            if(map[i][j] == '.') {
                minR = min(i, minR);
                minC = min(j, minC);
                maxR = max(i, maxR);
                maxC = max(j, maxC);
            }
        }
    }
    
    for(int i=minR; i<=maxR; i++) {
        for(int j=minC; j<=maxC; j++) {
            if(map[i][j] != '.') cout<<'#';
            else cout<<'.';
        }
        cout<<"\n";
    }
}

