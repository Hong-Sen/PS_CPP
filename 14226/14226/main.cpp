#include <iostream>
#include <queue>
#define MAX 2002
using namespace std;

bool visited[MAX][MAX]; //{이모티콘수,clip의 이모티콘 수}

struct imoticon{
    int screen;
    int clipboard;
    int Time;
};

int bfs(int s){
    queue<imoticon> q;
    q.push({1,0});
    visited[1][0] = true;
    while (!q.empty()) {
        int monitor = q.front().screen;
        int clip = q.front().clipboard;
        int time = q.front().Time;
        if(monitor == s)    return time;
        q.pop();
        //삭제하기
        if(monitor-1 >= 0 && !visited[monitor-1][clip]){
            visited[monitor-1][clip] = true;
            q.push({monitor-1, clip, time+1});
        }
        //복사하기
        if(monitor < 1001 && !visited[monitor][monitor]){
            visited[monitor][monitor] = true;
            q.push({monitor, monitor, time+1});
        }
        //붙여넣기
        if(monitor+clip < MAX && !visited[monitor+clip][clip]){
            visited[monitor+clip][clip] = true;
            q.push({monitor+clip, clip, time+1});
        }
    }
    return 0;
}

int main(){
    int s;
    cin>>s;
    cout<<bfs(s);
}
