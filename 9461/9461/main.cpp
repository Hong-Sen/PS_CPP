#include <iostream>
using namespace std;

long long dp[101];

long long padoban(int n){
    if(n<4) return 1;
    else{
        if(dp[n] == 0) return dp[n] = padoban(n-2) + padoban(n-3);
        else    return dp[n];
    }
}
int main(){
    int t;
    cin>>t;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        cout<<padoban(n)<<"\n";
    }
}
