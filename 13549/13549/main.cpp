#include <iostream>
#include <deque>
#define MAX 100001
using namespace std;

bool visited[100001];

int bfs(int n, int k){
    deque<pair<int, int>> dq;
    dq.push_front({n,0});
    visited[n] = true;
    
    while (!dq.empty()) {
        int curN = dq.front().first;
        int curTime = dq.front().second;
        dq.pop_front();
        
        if(curN == k)   return curTime;
        if(curN*2 < MAX && !visited[curN*2]){
            dq.push_front({curN * 2, curTime});
            visited[curN * 2] = true;
        }
        if(curN+1< MAX && !visited[curN+1]){
            dq.push_back({curN + 1, curTime+1});
            visited[curN + 1] = true;
        }
        if(curN -1 >= 0 && !visited[curN-1]){
            dq.push_back({curN - 1, curTime+1});
            visited[curN-1] = true;
        }
    }
    return 0;
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<bfs(n, k);
}

