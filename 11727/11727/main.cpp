#include <iostream>
using namespace std;

long long dp[1001];

long long solve(int n){
    if(n<3){
        dp[1] = 1;
        dp[2] = 3;
    }
    if(dp[n] == 0){
        return dp[n] = (solve(n-1) + solve(n-2) + solve(n-2)) % 10007;
    }
    else{
        return dp[n] % 10007;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n);
}
