//
//  main.cpp
//  17070
//
//  Created by 홍세은 on 2022/01/11.
//

#include <iostream>
using namespace std;

int n;
bool map[17][17];
bool visited[17][17];
int answer;

string direction(int r1, int c1, int r2, int c2){
    if(r1==r2 && c1+1==c2) return "horizontal";
    if(r1+1==r2 && c1==c2) return "vertical";
    return "diagonal";
}

bool isInside(int r1, int c1, int r2, int c2){
    return r1>=0 && r2>=0 && c1>=0 && c2>=0 && r1<=n && r2<=n && c1<=n && c2<=n;
}

void dfs(int r1, int c1, int r2, int c2, int cnt){
    if(!isInside(r1, c1, r2, c2)) return;
    if(r2 == n && c2 == n){
        answer++;
        return;
    }
    string type = direction(r1, c1, r2, c2);
    if(type == "horizontal"){
        if(!visited[r2][c2+1] && !map[r2][c2+1]){
            visited[r2][c2+1] = true;
            dfs(r2, c2, r2, c2+1, cnt+1);
            visited[r2][c2+1] = false;
        }
        if(!visited[r2][c2+1] && !visited[r2+1][c2] && !visited[r2+1][c2+1] && !map[r2][c2+1] && !map[r2+1][c2] && !map[r2+1][c2+1]){
            visited[r2+1][c2+1] = true;
            dfs(r2, c2, r2+1, c2+1, cnt+1);
            visited[r2+1][c2+1] = false;
        }
    }
    else if(type == "vertical"){
        if(!visited[r2+1][c2] && !map[r2+1][c2]){
            visited[r2+1][c2] = true;
            dfs(r2, c2, r2+1, c2, cnt+1);
            visited[r2+1][c2] = false;
        }
        if(!visited[r2][c2+1] && !visited[r2+1][c2] && !visited[r2+1][c2+1] && !map[r2][c2+1] && !map[r2+1][c2] && !map[r2+1][c2+1]){
            visited[r2+1][c2+1] = true;
            dfs(r2, c2, r2+1, c2+1, cnt+1);
            visited[r2+1][c2+1] = false;
        }
    }
    else{
        if(!visited[r2][c2+1] && !map[r2][c2+1]){
            visited[r2][c2+1] = true;
            dfs(r2, c2, r2, c2+1, cnt+1);
            visited[r2][c2+1] = false;
        }
        if(!visited[r2+1][c2] && !map[r2+1][c2]){
            visited[r2+1][c2] = true;
            dfs(r2, c2, r2+1, c2, cnt+1);
            visited[r2+1][c2] = false;
        }
        if(!visited[r2][c2+1] && !visited[r2+1][c2] && !visited[r2+1][c2+1] && !map[r2][c2+1] && !map[r2+1][c2] && !map[r2+1][c2+1]){
            visited[r2+1][c2+1] = true;
            dfs(r2, c2, r2+1, c2+1, cnt+1);
            visited[r2+1][c2+1] = false;
        }
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
        }
    }
    visited[1][1] = true;
    visited[1][2] = true;
    dfs(1, 1, 1, 2, 0);
    cout<<answer<<"\n";
}
