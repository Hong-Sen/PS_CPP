//
//  main.cpp
//  14499
//
//  Created by 홍세은 on 2022/05/10.
//

#include <iostream>
#include <vector>
using namespace std;

int N,M,diceRow,diceCol,K;
int map[21][21];
int dice[7] = {0,0,0,0,0,0,0};
int dy[5] = {0,0,0,-1,1};
int dx[5] = {0,1,-1,0,0};

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
    int nextR = diceRow + dy[move];
    int nextC = diceCol + dx[move];
    if(nextR >= 0 && nextR < N && nextC >=0 && nextC < M) {
        roll(move);
        if(map[nextR][nextC] == 0){
            map[nextR][nextC] = dice[6];
        }
        else {
            dice[6] = map[nextR][nextC];
            map[nextR][nextC] = 0;
        }
        diceRow = nextR;
        diceCol = nextC;
        cout<<dice[1]<<"\n";
    }
}

int main(){
    cin>>N>>M>>diceRow>>diceCol>>K;
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
