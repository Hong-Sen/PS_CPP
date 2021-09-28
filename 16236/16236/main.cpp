#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[22][22];
int visited[22][22];
int nowX, nowY;
int sharkSize = 2;
int fishCnt;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<pair<pair<int, int>, int>> closeFish; //{거리, y, x}
int result;

bool isInside(int x, int y){
    if(x>=0 && y>=0 && x<n && y<n) return true;
    else return false;
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if(visited[ny][nx] == 0 && isInside(nx, ny) && arr[ny][nx] <= sharkSize){
                visited[ny][nx] = visited[curY][curX] + 1;
                if(arr[ny][nx] < sharkSize && arr[ny][nx] > 0){
                    closeFish.push_back({{visited[ny][nx],ny},nx});
                }
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 9){
                nowY = i;
                nowX = j;
                arr[i][j] = 0;
            }
        }
    }
    
    while (1) {
        bfs(nowX, nowY);
        if(closeFish.empty()){
            cout<<result;
            return 0;
        }
        else{
            fishCnt++;
            sort(closeFish.begin(), closeFish.end());
            result += closeFish[0].first.first;
            nowX = closeFish[0].second;
            nowY = closeFish[0].first.second;
            arr[nowY][nowX] = 0;
            if(fishCnt == sharkSize){
                sharkSize++;
                fishCnt = 0;
            }
            closeFish.clear();
            memset(visited, 0, sizeof(visited));
        }
    }
}
