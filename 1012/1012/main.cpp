#include <iostream>
using namespace std;

int arr[51][51];
bool visited[51][51];
int t,m,n,k;
int cnt;
int deltax[] = {-1,1,0,0};
int deltay[] = {0,0,-1,1};

void revisited(){
    for(int i=0; i<51; i++){
        for(int j=0; j<51; j++)
            visited[i][j] = false;
    }
}

void reArr(){
    for(int i=0; i<51; i++){
        for(int j=0; j<51; j++)
            arr[i][j] = 0;
    }
}

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int dy = x + deltax[i];
        int dx = y + deltay[i];
        
        if(0<=dy && dy<m && 0<=dx && dx<n && !visited[dy][dx] && arr[dy][dx] == 1)
            dfs(dy,dx);
    }
}

void cabage(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                cnt++;
                dfs(i,j);
                
            }
        }
    }
}

int main(){
    
    cin>>t;
    for(int i=0; i<t; i++){
        revisited();
        reArr();
        cnt = 0;
        cin>>m>>n>>k;
        for(int j=0; j<k; j++){
            int x,y;
            cin>>x>>y;
            arr[x][y] = 1;
        }
//
//        for(int i=0; i<n; i++){
//            for(int j=0; j<m; j++)
//                 cout<<arr[i][j]<<" ";
//            cout<<"\n";
//        }
        
        cabage();
        cout<<cnt<<"\n";
    }
    
}
