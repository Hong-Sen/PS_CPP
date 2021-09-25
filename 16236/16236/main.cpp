#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[22][22];
int result;
int sharkSize = 2;
int eatCnt;
int dis;
int nowX,nowY;
vector<pair<pair<int, int>, int>> v; //물고기의 거리, y, x
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int visited[22][22];

bool isInside(int x, int y){
    if(x>=0 && y>=0 && x<n && y<n) return true;
    else return false;
}

void bfs(int x, int y){
    dis = 987654321;
    v.clear();
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({x,y});
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx, ny) && visited[ny][nx] == 0 && sharkSize >= arr[ny][nx]){
                visited[ny][nx] = visited[cy][cx] + 1;
                if(arr[ny][nx] > 0 && arr[ny][nx] < sharkSize){
                    if(dis >= visited[ny][nx]){
                        dis = visited[ny][nx];
                        v.push_back({{dis,ny},nx});
                    }
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
                nowX = j;
                nowY = i;
                arr[i][j] = 0;
                continue;
            }
        }
    }
    while (1) {
        bfs(nowX, nowY);
        if(v.empty())   break;
        else{
            sort(v.begin(),v.end());
            eatCnt++;
            result += v[0].first.first;
            arr[v[0].first.second][v[0].second] = 0; //현재위치
            nowY = v[0].first.second;
            nowX = v[0].second;
            if(sharkSize == eatCnt){
                sharkSize++;
                eatCnt = 0;
            }
        }
    }
    cout<<result;
}
