#include <iostream>
#include <queue>
using namespace std;

int N;
int board[21][21];
int result;

int findMax(int map[21][21]){
    int maxNum = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            maxNum = max(maxNum, map[i][j]);
        }
    }
    return maxNum;
}

void playGame(int cnt, int map[21][21]){
    if(cnt == 5){
        result = max(result, findMax(map));
        return;
    }
    
    int upMap[21][21], downMap[21][21], rightMap[21][21], leftMap[21][21];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            upMap[i][j] = 0;
            downMap[i][j] = 0;
            rightMap[i][j] = 0;
            leftMap[i][j] = 0;
        }
    }
    
    // 전체 블록 이동
    queue<int> q;
    // 상
    for(int j=0; j<N; j++){
        for(int i=0; i<N; i++){
            if(map[i][j] != 0) q.push(map[i][j]);
        }
        int idx = 0;
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if(upMap[idx][j] == 0) upMap[idx][j] = num;
            else{
                if(upMap[idx][j] == num){
                    upMap[idx][j] = num*2;
                    idx++;
                }
                else{
                    upMap[++idx][j] = num;
                }
            }
        }
    }
    playGame(cnt+1, upMap);

    // 하
    for(int j=0; j<N; j++){
        for(int i=N-1; i>=0; i--){
            if(map[i][j] != 0) q.push(map[i][j]);
        }
        int idx = N-1;
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if(downMap[idx][j] == 0) downMap[idx][j] = num;
            else{
                if(downMap[idx][j] == num){
                    downMap[idx][j] = num*2;
                    idx--;
                }
                else{
                    downMap[--idx][j] = num;
                }
            }
        }
    }
    playGame(cnt+1, downMap);

     // 좌
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] != 0) q.push(map[i][j]);
        }
        int idx = 0;
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if(leftMap[i][idx] == 0) leftMap[i][idx] = num;
            else{
                if(leftMap[i][idx] == num){
                    leftMap[i][idx] = num*2;
                    idx++;
                }
                else{
                    leftMap[i][++idx] = num;
                }
            }
        }
    }
    playGame(cnt+1, leftMap);
    
    // 우
    for(int i=0; i<N; i++){
        for(int j=N-1; j>=0; j--){
            if(map[i][j] != 0) q.push(map[i][j]);
        }
        int idx = N-1;
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if(rightMap[i][idx] == 0) rightMap[i][idx] = num;
            else{
                if(rightMap[i][idx] == num){
                    rightMap[i][idx] = num*2;
                    idx--;
                }
                else{
                    rightMap[i][--idx] = num;
                }
            }
        }
    }
    playGame(cnt+1, rightMap);
}

int main(){
    cin>>N;
    int x;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
        }
    }
    
    playGame(0, board);
    
    cout<<result;
}
