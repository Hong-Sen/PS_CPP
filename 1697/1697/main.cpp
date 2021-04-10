#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

bool visited[100001];

int findSis(int n, int k){
    queue<pair<int, int>> q;
    q.push({n,0});
    visited[n] = true;
    
    while (!q.empty()) {
        int curN = q.front().first;
        int curTime = q.front().second;
        q.pop();
        
        if(curN == k)   return curTime;
        if(curN*2 < MAX && !visited[curN*2]){
                            q.push({curN * 2, curTime+1});
                            visited[curN * 2] = true;
                        }
        if(curN+1< MAX && !visited[curN+1]){
            q.push({curN + 1, curTime+1});
            visited[curN + 1] = true;
        }
        if(curN -1 >= 0 && !visited[curN-1]){
            q.push({curN - 1, curTime+1});
            visited[curN-1] = true;
        }
            }
    return 0;
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<findSis(n, k);
}
