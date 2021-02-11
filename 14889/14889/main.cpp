#include <iostream>
#include <cmath>
#define MIN(x,y) (x>y ? y : x)
using namespace std;

int n;
int num[20];
int soccer[20][20];
bool visited[20];
int result = 100000000;

void dfs(int cnt,int index){
    if(cnt == n/2){
        int start = 0,link = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visited[i] && visited[j])    start += soccer[i][j];
                if(!visited[i] && !visited[j])  link += soccer[i][j];
            }
        }
        result = MIN(abs(start-link),result);
    }
    for(int i=index; i<n; i++){
        visited[i] = true;
        dfs(cnt+1, i+1);
        visited[i] = false;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>soccer[i][j];
        }
    }
    dfs(0, 0);
    cout<<result;
}
