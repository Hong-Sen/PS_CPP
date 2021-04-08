#include <iostream>
using namespace std;

long dp[1002][1002];

long fibo(int n,int m){
    if(n==0 || m==0)    return 0;
    if((n==1 && m==1))  return 1;
    if(dp[n][m] != -1)  return dp[n][m];
    dp[n][m] = (fibo(n-1, m-1) + fibo(n-1, m) + fibo(n, m-1)) % 1000000007;
    return dp[n][m];
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j]= -1;
        }
    }
    cout<<fibo(n, m) % 1000000007;
}

