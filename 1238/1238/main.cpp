#include <iostream>
#define INF 9999999
using namespace std;

int arr[1001][1001];

void floyd(int n){
    for(int mid=1; mid<=n; mid++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j] > arr[i][mid] + arr[mid][j])
                    arr[i][j] = arr[i][mid] + arr[mid][j];
            }
        }
    }
}


int main(){
    int n,m,x,a,b,t;
    cin>>n>>m>>x;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] = INF;
            if(i==j)    arr[i][j] = 0;
        }
    }
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>t;
        arr[a][b] = t;
    }
    
    floyd(n);
    
    int maxTime = 0;
    for(int i=1; i<=n; i++){
        if(maxTime < arr[i][x] + arr[x][i])
            maxTime = arr[i][x] + arr[x][i];
    }
    cout<<maxTime;
    
    
}
