#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, T, A, B, C;
vector<pair<int, int>> v[50001];
bool visited[50001];
int lastNode;
long long totalCnt, totalTime;

void dfs(int cur, int cnt, long long time){
    visited[cur] = true;
    if(totalCnt < cnt) {
        totalCnt = cnt;
        totalTime = time;
        lastNode = cur;
    }
    else if(totalCnt == cnt && totalTime > time){
        totalTime = time;
        lastNode = cur;
    }
    
    for(int i=0; i<v[cur].size(); i++){
        int next = v[cur][i].first;
        int nextValue = v[cur][i].second;
        if(!visited[next]){
            dfs(next, cnt+1, time+nextValue);
        }
    }
}

int main(){
    cin>>N>>T;
    for(int i=0; i<N-1; i++){
        cin>>A>>B>>C;
        v[A].push_back({B,C});
        v[B].push_back({A,C});
    }
    dfs(1, 0, 0);
    
    totalCnt = 0;
    totalTime = 0;
    
    memset(visited, false, sizeof(visited));
    dfs(lastNode, 0, 0);
    
    int answer = (totalTime % T == 0) ? (totalTime / T) : (totalTime / T + 1);
    cout<<answer;
    
}

