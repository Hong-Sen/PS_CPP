#include <iostream>
using namespace std;

long long dp[117];

long long solve(int n){
    if(n<4){
        dp[n] = 1;
    }
    if(dp[n] == 0){
        return dp[n] = solve(n-1) + solve(n-3);
    }
    else{
        return dp[n];
    }
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n);
}
