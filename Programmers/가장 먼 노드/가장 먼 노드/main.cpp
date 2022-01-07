#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dis[20001];
bool visited[20001];
vector<int> v[20001];
queue<int> q;
int maxLength;

void bfs(){
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i];
            if(!visited[next]){
                q.push(next);
                dis[next] = dis[cur]+1;
                visited[next] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0; i<edge.size(); i++){
        for(int j=0; j<2; j++){
            v[edge[i][0]].push_back(edge[i][1]);
            v[edge[i][1]].push_back(edge[i][0]);
        }
    }
    q.push(1);
    visited[1] = true;
    bfs();
    for(int i=1; i<=n; i++){
        if(dis[i] > maxLength){
            maxLength = dis[i];
            answer = 0;
        }
        if(dis[i] == maxLength){
            answer++;
        }
    }
    return answer;
}

int main(){
    cout<<solution(6, {{3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2}});
}
