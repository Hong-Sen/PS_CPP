#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[25][25];
bool visited[25][25];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> v;
int cnt;

void dfs(int x,int y){
    cnt++;
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n)  continue;
        if(map[nx][ny] == 1 && !visited[nx][ny])    dfs(nx, ny);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
            map[i][j] = s.at(j)-48;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1 && !visited[i][j]){
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
                
        }
    }
    cout<<v.size()<<"\n";
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
    cout<<v[i]<<"\n";
}
