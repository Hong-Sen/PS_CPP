#include <iostream>
#include <queue>
using namespace std;

int n,m;
int arr[505][505];
int visited[505][505];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int, int>> q;
priority_queue<int> result;
int cnt;

bool isInside(int x, int y){
    if(x>=0 && y>=0 && x<m && y<n) return true;
    else return false;
}

void bfs(){
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visited[y][x] = cnt;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isInside(nx, ny) && visited[ny][nx] == 0 && arr[ny][nx] == 1){
                cnt++;
                visited[ny][nx] = cnt;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1 && visited[i][j] == 0){
                cnt = 1;
                q.push({j,i});
                bfs();
                result.push(cnt);
            }
        }
    }
    if(result.size() == 0) cout<<0<<"\n"<<0;
    else cout<<result.size()<<"\n"<<result.top()<<"\n";
}
