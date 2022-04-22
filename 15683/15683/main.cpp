//
//  main.cpp
//  15683
//
//  Created by 홍세은 on 2022/03/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int map[9][9];
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
vector<pair<int ,pair<int, int>>> cctv; // {cctv number, {row, col}}
int result = 100;

void findSquare(int cctvMap[9][9]){
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(cctvMap[i][j] == 0) sum++;
        }
    }
    result = min(sum, result);
}

void seeThrowCctv(int row, int col, int dir, int cctvMap[9][9]) {
    if(row>=0 && row<n && col>=0 && col<m && map[row][col] != 6){
        cctvMap[row][col] = 9;
        seeThrowCctv(row+direction[dir][0], col+direction[dir][1], dir, cctvMap);
    }
}

void dfs(int idx, int cctvMap[9][9]){
    if(idx == cctv.size()){
        findSquare(cctvMap);
        return;
    }
    int row = cctv[idx].second.first;
    int col = cctv[idx].second.second;
    int tmpMap[9][9];
    
    switch (cctv[idx].first) {
        case 1:
            for(int i=0; i<4; i++){
                copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
                seeThrowCctv(row, col, i, tmpMap);
                dfs(idx+1, tmpMap);
            }
            break;
            
        case 2:
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 0, tmpMap);
            seeThrowCctv(row + direction[1][0], col + direction[1][1], 1, tmpMap);
            dfs(idx+1, tmpMap);
            
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 2, tmpMap);
            seeThrowCctv(row + direction[3][0], col + direction[3][1], 3, tmpMap);
            dfs(idx+1, tmpMap);
            break;
            
        case 3:
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 0, tmpMap);
            seeThrowCctv(row + direction[2][0], col + direction[2][1], 2, tmpMap);
            dfs(idx+1, tmpMap);
            
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 0, tmpMap);
            seeThrowCctv(row + direction[3][0], col + direction[3][1], 3, tmpMap);
            dfs(idx+1, tmpMap);
            
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 1, tmpMap);
            seeThrowCctv(row + direction[2][0], col + direction[2][1], 2, tmpMap);
            dfs(idx+1, tmpMap);
            
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 1, tmpMap);
            seeThrowCctv(row + direction[3][0], col + direction[3][1], 3, tmpMap);
            dfs(idx+1, tmpMap);
            
            break;
            
        case 4:
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 1, tmpMap);
            seeThrowCctv(row + direction[2][0], col + direction[2][1], 2, tmpMap);
            seeThrowCctv(row + direction[3][0], col + direction[3][1], 3, tmpMap);
            dfs(idx+1, tmpMap);
            
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 0, tmpMap);
            seeThrowCctv(row + direction[1][0], col + direction[1][1], 1, tmpMap);
            seeThrowCctv(row + direction[2][0], col + direction[2][1], 2, tmpMap);
            dfs(idx+1, tmpMap);
            
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 0, tmpMap);
            seeThrowCctv(row + direction[2][0], col + direction[2][1], 2, tmpMap);
            seeThrowCctv(row + direction[3][0], col + direction[3][1], 3, tmpMap);
            dfs(idx+1, tmpMap);
            
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 0, tmpMap);
            seeThrowCctv(row + direction[1][0], col + direction[1][1], 1, tmpMap);
            seeThrowCctv(row + direction[3][0], col + direction[3][1], 3, tmpMap);
            dfs(idx+1, tmpMap);
            
            break;
            
        case 5:
            copy(&cctvMap[0][0], &cctvMap[0][0]+81, &tmpMap[0][0]);
            seeThrowCctv(row, col, 0, tmpMap);
            seeThrowCctv(row + direction[1][0], col + direction[1][1], 1, tmpMap);
            seeThrowCctv(row + direction[2][0], col + direction[2][1], 2, tmpMap);
            seeThrowCctv(row + direction[3][0], col + direction[3][1], 3, tmpMap);
            dfs(idx+1, tmpMap);

        default:
            break;
    }
}


int main(){
    cin>>n>>m;
    int cctvMap[9][9];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>map[i][j];
            cctvMap[i][j] = map[i][j];
            if(map[i][j] >= 1 && map[i][j] <=5) cctv.push_back({map[i][j], {i,j}});
        }
    }
    sort(cctv.begin(), cctv.end(), greater<>());
    dfs(0, cctvMap);
    cout<<result;
}
