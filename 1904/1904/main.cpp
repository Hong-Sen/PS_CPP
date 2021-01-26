#include <iostream>
using namespace std;

int dp[1000001];

int tile(int n){
    if(n==1)    return 1;
    else if(n==2)   return 2;
    if(dp[n]==0)    return dp[n] = (tile(n-1) + tile(n-2))%15746;
    else    return dp[n]%15746;
}

int main(){
    int n;
    cin>>n;
    cout<<tile(n);
}
