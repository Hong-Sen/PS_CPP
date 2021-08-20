#include <iostream>
#include <queue>
using namespace std;

int a,b;
queue<pair<int, int>> q; //{num,cnt}

int bfs(){
    q.push({a,1});
    while (!q.empty()) {
        long long cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == b){
            return cnt;
        }
        if(cur*2 <= b){
            q.push({cur*2, cnt+1});
        }
        cur = cur*10 + 1;
        if(cur <= b){
            q.push({cur, cnt+1});
        }
    }
    return -1;
}

int main(){
    cin>>a>>b;
    cout<<bfs();
}
