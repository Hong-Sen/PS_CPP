//
//  main.cpp
//  5014
//
//  Created by 홍세은 on 2022/03/16.
//

#include <iostream>
#include <queue>
using namespace std;

int F,S,G,U,D;
bool visited[1000001];
queue<pair<int, int>> q;

int main(){
    cin>>F>>S>>G>>U>>D;
    q.push({S,0});
    visited[S] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == G) {
            cout<<cnt<<"\n";
            return 0;
        }
        
        if(cur + U <= F && !visited[cur + U]) {
            visited[cur + U] = true;
            q.push({cur + U, cnt + 1});
        }
        
        if(cur - D >= 1 && !visited[cur - D]) {
            visited[cur - D] = true;
            q.push({cur - D, cnt + 1});
        }
    }
    cout<< "use the stairs";
}
