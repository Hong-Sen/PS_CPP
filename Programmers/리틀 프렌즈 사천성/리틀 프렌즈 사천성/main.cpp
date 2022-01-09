#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int M,N;

bool isInside(int row, int col ){
    return row>=0 && row<M && col>=0 && col<N;
}

int bfs(int row, int col, int color, vector<vector<int>> picture, int cnt, bool isVisited[101][101]){
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    queue<pair<int,int>> q;
    q.push({row, col});
    isVisited[row][col] = true;
    while(!q.empty()){
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nextR = curR + dy[i];
            int nextC = curC + dx[i];
            if(isInside(nextR, nextC) && !isVisited[nextR][nextC] && picture[nextR][nextC] == color){
                cnt++;
                isVisited[nextR][nextC] = true;
                q.push({nextR, nextC});
            }
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    M = m;
    N = n;
    vector<int> answer(2);
    bool isVisited[101][101] = {false,};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!isVisited[i][j] && picture[i][j] != 0){
                number_of_area++;
                max_size_of_one_area = max(bfs(i,j,picture[i][j],picture,1,isVisited), max_size_of_one_area);
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
