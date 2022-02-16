#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int map[9][9];
int wall;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int, int>> q;
int result;

bool isInside(int row, int col){
    if(row>=0 && row<n && col>=0 && col<m) return true;
    return false;
}

int infection(int tmp[][9]){
    queue<pair<int, int>> q2;
    int cnt = 0;
//
    q2 = q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp[i][j] == 2)  q2.push({i,j});
            cout<<tmp[i][j]<<" ";
        }
        cout<<"\n";
    }
    while (!q2.empty()) {
        int cr = q2.front().first;
        int cc = q2.front().second;
        cout<<cr<<" "<<cc<<"\n";
        cnt++;
        q2.pop();
        for(int i=0; i<4; i++){
            int nr = cr + dy[i];
            int nc = cc + dx[i];
            if(isInside(nr, nc) && tmp[nr][cc] == 0){
                q2.push({nr, nc});
                tmp[nr][nc] = 2;
            }
        }
    }
    return n * m - wall - cnt;
}

void makeWall(int tmp[][9], int cnt){
    if(cnt == 3){
        cout<<"cnt3\n";
        result = max(result, infection(tmp));
        cout<<"result: "<<result<<"\n";
    }
    
    int (*map2)[9] = tmp;
    for(int i=0; i<n; i++){
        cout<<"i: "<<i<<"\n";
        for(int j=0; j<m; j++){
            if(map2[i][j] == 0){
                map2[i][j] = 1;
                makeWall(map2, cnt+1);
                map2[i][j] = 0;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j] == 2) q.push({i,j});
            if(map[i][j] == 1) wall++;
        }
    }
    makeWall(map, 0);
    cout<<result;

}
