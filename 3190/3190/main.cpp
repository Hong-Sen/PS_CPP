//
//  main.cpp
//  3190
//
//  Created by 홍세은 on 2022/03/23.
//

#include <iostream>
#include <queue>
using namespace std;

int N,K,L;
int map[101][101];
queue<pair<int, char>> q;
int endTime;

bool isInside(int r, int c){
    return r>=0 && r<N && c>=0 && c<N;
}

void dfs(int curLocation[2], queue<pair<int, int>> snakeOrder, int time, char d, int snake[101][101]){
    // 종료 조건: 벽 또는 자기자신과 부딫힘
    if(!isInside(curLocation[0], curLocation[1]) || snake[curLocation[0]][curLocation[1]] == 1){
        endTime = time;
        cout<<endTime<<"\n";
        return;
    }
    
    // 머리 이동
    snake[curLocation[0]][curLocation[1]] = 1;
    snakeOrder.push({curLocation[0], curLocation[1]});
    
    // 사과x
    if(time != 0 && map[curLocation[0]][curLocation[1]] == 0){
        // 꼬리 이동
        snake[snakeOrder.front().first][snakeOrder.front().second] = 0;
        snakeOrder.pop();
    }
    // 사과 먹었으면 없애기!
    else if(map[curLocation[0]][curLocation[1]] == 1) {
        map[curLocation[0]][curLocation[1]] = 0;
    }
    
    char nextD = d;
    if(q.front().first == time) {
        int spinDirection = q.front().second;
        q.pop();
        if(spinDirection == 'D') {
            switch (d) {
                case 'E':
                    nextD = 'S';
                    break;
                case 'W':
                    nextD = 'N';
                    break;
                case 'N':
                    nextD = 'E';
                    break;
                case 'S':
                    nextD = 'W';
                    break;
                default:
                    break;
            }
        }
        if(spinDirection == 'L') {
            switch (d) {
                case 'E':
                    nextD = 'N';
                    break;
                case 'W':
                    nextD = 'S';
                    break;
                case 'N':
                    nextD = 'W';
                    break;
                case 'S':
                    nextD = 'E';
                    break;
                default:
                    break;
            }
        }
    }
    
    switch (nextD) {
        case 'E':
            curLocation[1] += 1;
            dfs(curLocation, snakeOrder, time+1, nextD, snake);
            break;
        case 'W':
            curLocation[1] -= 1;
            dfs(curLocation, snakeOrder,time+1, nextD, snake);
            break;
        case 'N':
            curLocation[0] -= 1;
            dfs(curLocation, snakeOrder, time+1, nextD, snake);
            break;
        case 'S':
            curLocation[0] += 1;
            dfs(curLocation, snakeOrder, time+1, nextD, snake);
            break;
            
        default:
            break;
    }
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
    char c;
    for(int i=0; i<L; i++){
        cin>>t>>c;
        q.push({t,c});
    }
    int snake[101][101] = {0,};
    int curLocation[2] = {0,0};
    queue<pair<int, int>> snakeOrder;
    dfs(curLocation, snakeOrder, 0, 'E', snake);
}
