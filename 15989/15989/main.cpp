#include <iostream>
using namespace std;

int dp[10001][4];

int main(){
    int t,n;
    dp[1][1] = 1; //n=1이고 마지막 숫자가 1인 값
    dp[1][2] = 0; //n=1이고 마지막 숫자가 2인 값
    dp[1][3] = 0; //n=1이고 마지막 숫자가 3인 값
    
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 0;
    
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for(int i=4; i<=10000; i++){
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        int sum = dp[n][1] + dp[n][2] + dp[n][3];
        cout<<sum<<"\n";
    }
}
