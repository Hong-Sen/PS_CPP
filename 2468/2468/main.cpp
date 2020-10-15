#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int m[101][101];
bool visited[101][101];
priority_queue<int> pq;
int n,cnt = 1,maxh;
//상하좌우
int deltax[] = {-1,1,0,0};
int deltay[] = {0,0,-1,1};

bool isValid(int a, int b){
    return (a>=0 && a<n) &&(b>=0 && b<n);
}

void revisited(){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++)
            visited[i][j] = false;
    }
}

void dfs(int a, int b, int h){
    visited[a][b] = true;
    //(a-1,b),(a+1,b),(a,b-1),(a,b+1)
    for(int i=0; i<4; i++){
        int dy = a + deltax[i];
        int dx = b + deltay[i];
        
        if(isValid(dy, dx) && m[dy][dx] > h && !visited[dy][dx] ){
            dfs(dy, dx, h);
        }
    }
}

void SafeArea(int n){
    for(int h=1; h<=maxh; h++){
        cnt = 0;
        revisited();
        for(int i=0; i<n; i++){
            for(int j=0 ;j<n; j++)
            if(m[i][j] > h && !visited[i][j]){
                cnt++;
                dfs(i, j, h);
            }
        }
        pq.push(cnt);
        
    }

        
    pq.push(1);
    cout<<pq.top()<<"\n";

}

int main(){
    cin>>n;
    for(int i=0; i<n ;i++){
        for(int j=0; j<n; j++){
            cin>>m[i][j];
            if(maxh <  m[i][j]) maxh = m[i][j];
        }
            
    }
    
    SafeArea(n);
    
    return 0;
}
