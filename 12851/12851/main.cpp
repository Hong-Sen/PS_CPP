#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;

bool visited[MAX];
int resultTime = MAX;
int resultCnt;

void bfs(int n, int k){
    queue<pair<int, int>> q;
    q.push({n,0});
    visited[n] = true;
    
    while (!q.empty()) {
        int curN = q.front().first;
        int curTime = q.front().second;
        q.pop();
        visited[curN] = true;
        if(curTime > resultTime)    continue;
        
        if(curN == k){
            resultTime = min(curTime, resultTime);
            resultCnt++;
            continue;
        }
        if(curN*2 < MAX && !visited[curN*2]){
            q.push({curN * 2, curTime+1});
        }
        if(curN+1< MAX && !visited[curN+1]){
            q.push({curN + 1, curTime+1});
        }
        if(curN -1 >= 0 && !visited[curN-1]){
            q.push({curN - 1, curTime+1});
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    bfs(n, k);
    cout<<resultTime<<"\n"<<resultCnt;
}

