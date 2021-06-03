#include <iostream>
using namespace std;

int dp[2000001];

int fibonachiP(int n){
    
    if(n<=2)    return 1;
    if(dp[n] != 0)  return dp[n];
    else{
        dp[n] = (fibonachiP(n-1) + fibonachiP(n-2))% 1000000000;;
        return dp[n];
    }
}

int fibonachiN(int n){
    for(int i=2; i<=n; i++){
        dp[i] = (dp[i-2] - dp[i-1]) % 1000000000;
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    dp[0] = 0;
    dp[1] = 1;
    int x = n>0 ? fibonachiP(n) : fibonachiN(-n);
    if(x > 0)   cout<<"1\n";
    else if(x == 0) cout<<"0\n";
    else    cout<<"-1\n";
    cout<<abs(x);
}
