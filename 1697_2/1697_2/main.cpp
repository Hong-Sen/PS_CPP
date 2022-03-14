//
//  main.cpp
//  1697_2
//
//  Created by 홍세은 on 2022/03/15.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

int n,k;
bool visited[100001];
queue<pair<int, int>> q;

int bfs(){
    q.push({n,0});
    while (!q.empty()) {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();
        if(cur == k){
            return time;
        }
        if(cur-1 >= 0 && !visited[cur-1]) {
            visited[cur-1] = true;
            q.push({cur-1, time+1});
        }
        if(cur+1 < MAX && !visited[cur+1]) {
            visited[cur+1] = true;
            q.push({cur+1, time+1});
        }
        if(cur*2 < MAX && !visited[cur*2]) {
            visited[cur*2] = true;
            q.push({cur*2, time+1});
        }
    }
    return 0;
}

int main(){
    cin>>n>>k;
    cout<<bfs();
}
