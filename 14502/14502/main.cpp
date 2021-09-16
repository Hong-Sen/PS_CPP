#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int map[10][10];
vector<pair<int, int>> v; // 0인 공간
queue<pair<int, int>> q; // 2인 공간
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int result;

int infection(vector<pair<int, int>> v){
    queue<pair<int, int>> tq = q;
    int arr[n][m];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = map[i][j];
        }
    }
    // 3개 벽으로 막기
    for(int i=0; i<3; i++){
        arr[v[i].first][v[i].second] = 1;
    }
    
    while (!tq.empty()) {
        int y = tq.front().first;
        int x = tq.front().second;
        tq.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n && arr[ny][nx] == 0){
                arr[ny][nx] = 2;
                tq.push({ny,nx});
            }
        }
    }
    //find safe place
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0)  cnt++;
        }
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j] == 0) v.push_back({i,j});
            if(map[i][j] == 2) q.push({i,j});
        }
    }
    
    int vSize = v.size();
    // 3개읩 벽 선정
    for (int i=0; i<vSize-2; i++) {
        for(int j=i+1; j<vSize-1; j++){
            for(int l=j+1; l<vSize; l++){
                vector<pair<int, int>> tmp;
                tmp.push_back({v[i].first,v[i].second});
                tmp.push_back({v[j].first,v[j].second});
                tmp.push_back({v[l].first,v[l].second});
                result = max(infection(tmp),result);
            }
        }
    }
    cout<<result;
}
