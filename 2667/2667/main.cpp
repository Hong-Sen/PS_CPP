#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int m[25][25];
bool visited[25][25];
int cntSum; //총 단지수
vector<int> wholeCnt; //단지내 집 수
int n;
int cnt;

//상하좌우
int deltax[] = {-1,1,0,0};
int deltay[] = {0,0,-1,1};

bool isValid(int a, int b){
    return (a>=0 && a<n) &&(b>=0 && b<n);
}

void dfs(int a, int b){
    cnt++;
    visited[a][b] = true;
    
    //(a-1,b),(a+1,b),(a,b-1),(a,b+1)
    for(int i=0; i<4; i++){
        int dy = a + deltax[i];
        int dx = b + deltay[i];
        
        if(isValid(dy, dx) && !visited[dy][dx] && m[dy][dx] == 1){
            dfs(dy, dx);
        }
    }
    
}

void Complex(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(m[i][j] == 1 && !visited[i][j]){
                cnt = 0;
                dfs(i, j);
                cntSum++;
                wholeCnt.push_back(cnt);
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n ;i++){
        for(int j=0; j<n; j++)
            scanf("%1d", &m[i][j]);
    }

    Complex(n);

    cout<< cntSum <<"\n";
    sort(wholeCnt.begin(), wholeCnt.end());
    for(int i=0; i<cntSum; i++)
        cout<<wholeCnt[i]<<"\n";
      
        
    
}
