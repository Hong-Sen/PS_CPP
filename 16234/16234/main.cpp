#include <iostream>
#include <map>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

int N,L,R;
int population[52][52];
map<pair<int, int>, int> country;
bool visited[52][52];
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
int day;
bool flag;

void moved(){
    long long sum = 0;
    for(auto it: country) {
        sum += population[it.first.first][it.first.second];
    }
    sum /= country.size();
    for(auto it: country) {
        population[it.first.first][it.first.second] = sum;
    }
}

void bfs(int r, int c){
    country.clear();
    queue<pair<int, int>> q;
    q.push({r,c});
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nr = cr + dir[k][0];
            int nc = cc + dir[k][1];
            if(nr>=0 && nr<N && nc>=0 && nc<N && !visited[nr][nc]){
                int gap = abs(population[cr][cc] - population[nr][nc]);
                if(gap >= L && gap <= R){
                    visited[nr][nc] = true;
                    visited[cr][cc] = true;
                    country.insert({{nr,nc}, 0});
                    country.insert({{cr,cc}, 0});
                    q.push({nr,nc});
                    flag = true;
                }
            }
        }
    }
    if(country.size() > 1) moved();
}

bool isAvailable(){
    memset(visited, false, sizeof(visited));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                bfs(i, j);
            }
        }
    }
    return flag;
}

int main(){
    cin>>N>>L>>R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>population[i][j];
        }
    }
    
    while (1) {
        if(!isAvailable()) break;
        day++;
        flag = false;
    }

    cout<<day;
    
}
