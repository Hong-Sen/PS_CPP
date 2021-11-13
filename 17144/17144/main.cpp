#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R,C,T;
int arr[51][51];
int arr2[51][51];
vector<pair<int, int>> con;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<pair<int, int>> q1;
int sum;

bool isInside(int row, int col){
    if(row>=0 && row<R && col>=0 && col<C)  return true;
    else return false;
}

bool isNotCon(int row, int col){
    if(row == con[0].first || row == con[1].first){
        if(col == 0)    return false;
    }
    return true;
}

void test(){
    // 미세먼지 확산
    sum = 0;
    while (!q1.empty()) {
        int curR = q1.front().first;
        int curC = q1.front().second;
        q1.pop();
        int dust = arr[curR][curC];
        int cnt = 0;
        for(int i=0; i<4; i++){
            int nextR = curR + dy[i];
            int nextC = curC + dx[i];
            if(isInside(nextR, nextC) && isNotCon(nextR, nextC)){
                cnt++;
                arr2[nextR][nextC] += dust/5;
            }
        }
        arr2[curR][curC] += dust - ((dust/5) * cnt);
    }
    
    // 공기청정기 작동
    int con1 = con[0].first;
    int con2 = con[1].first;
    for(int i=con1-1; i>0; i--){
        arr2[i][0] = arr2[i-1][0];
    }
    for(int i=0; i<C-1; i++){
        arr2[0][i] = arr2[0][i+1];
    }
    for(int i=0; i<con1; i++){
        arr2[i][C-1] = arr2[i+1][C-1];
    }
    for(int i=C-1; i>0; i--){
        arr2[con1][i] = arr2[con1][i-1];
    }
    
    for(int i=con2+1; i<R-1; i++){
        arr2[i][0] = arr2[i+1][0];
    }
    for(int i=0; i<C-1; i++){
        arr2[R-1][i] = arr2[R-1][i+1];
    }
    for(int i=R-1; i>con2; i--){
        arr2[i][C-1] = arr2[i-1][C-1];
    }
    for(int i=C-1; i>0; i--){
        arr2[con2][i] = arr2[con2][i-1];
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            arr[i][j] = arr2[i][j];
            arr2[i][j] = 0;
            sum += arr[i][j];
            if(arr[i][j] != 0)  q1.push({i,j});
        }
    }
}

int main(){
    cin>>R>>C>>T;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>arr[i][j];
            if(arr[i][j] == -1){
                con.push_back({i,j});
                continue;
            }
            if(arr[i][j] != 0) q1.push({i,j});
        }
    }
    while (T--) {
        test();
    }
    cout<<sum<<"\n";
}
