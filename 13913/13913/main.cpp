#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

bool visited[MAX];
int parent[MAX];
vector<int> result;

int bfs(int n, int k){
    queue<pair<int, int>> q;
    q.push({n,0});
    visited[n] = true;
    
    while (!q.empty()) {
        int curLoc = q.front().first;
        int curTime = q.front().second;
        q.pop();
        
        if(curLoc == k){
            int i = k;
            while (i != n) {
                result.push_back(i);
                i = parent[i];
            }
            result.push_back(n);
            return curTime;
        }
        if(curLoc*2 < MAX && !visited[curLoc*2]){
            parent[curLoc*2] = curLoc;
            q.push({curLoc * 2, curTime+1});
            visited[curLoc * 2] = true;
        }
        if(curLoc+1< MAX && !visited[curLoc+1]){
            parent[curLoc+1] = curLoc;
            q.push({curLoc + 1, curTime+1});
            visited[curLoc + 1] = true;
        }
        if(curLoc -1 >= 0 && !visited[curLoc-1]){
            parent[curLoc-1] = curLoc;
            q.push({curLoc - 1, curTime+1});
            visited[curLoc-1] = true;
        }
    }
    return 0;
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<bfs(n, k)<<"\n";
    for(int i=result.size()-1; i>=0; i--)
        cout<<result[i]<<" ";
}

