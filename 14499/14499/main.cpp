//
//  main.cpp
//  14499
//
//  Created by 홍세은 on 2022/05/10.
//

#include <iostream>
#include <vector>
using namespace std;

int N,M,diceX,diceY,K;
int map[21][21];
int dice[7] = {0,0,0,0,0,0,0};
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

void roll(int move) {
    vector<int> tmp;
    switch (move) {
        case 1:
            tmp.push_back(dice[1]);
            tmp.push_back(dice[3]);
            tmp.push_back(dice[6]);
            tmp.push_back(dice[4]);
            dice[3] = tmp[0];
            dice[6] = tmp[1];
            dice[4] = tmp[2];
            dice[1] = tmp[3];
            break;
            
        case 2:
            tmp.push_back(dice[3]);
            tmp.push_back(dice[6]);
            tmp.push_back(dice[1]);
            tmp.push_back(dice[4]);
            dice[1] = tmp[0];
            dice[3] = tmp[1];
            dice[4] = tmp[2];
            dice[6] = tmp[3];
            break;
            
        case 3:
            tmp.push_back(dice[1]);
            tmp.push_back(dice[5]);
            tmp.push_back(dice[6]);
            tmp.push_back(dice[2]);
            dice[2] = tmp[0];
            dice[1] = tmp[1];
            dice[5] = tmp[2];
            dice[6] = tmp[3];
            break;
            
        case 4:
            tmp.push_back(dice[1]);
            tmp.push_back(dice[2]);
            tmp.push_back(dice[6]);
            tmp.push_back(dice[5]);
            dice[5] = tmp[0];
            dice[1] = tmp[1];
            dice[2] = tmp[2];
            dice[6] = tmp[3];
            break;
            
        default:
            break;
    }
}

void play(int move) {
    int nextX = diceX + dx[move];
    int nextY = diceY + dy[move];
    if(nextX >= 0 && nextX < N && nextY >=0 && nextY < M) {
        roll(move);
        if(map[nextX][nextY] == 0){
            map[nextX][nextY] = dice[6];
        }
        else {
            dice[6] = map[nextX][nextY];
            map[nextX][nextY] = 0;
        }
        diceX = nextX;
        diceY = nextY;
        cout<<dice[1]<<"\n";
    }
}

int main(){
    cin>>N>>M>>diceX>>diceY>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    int move = 0;
    for(int i=0; i<K; i++){
        cin>>move;
        play(move);
    }
    
}
