#include <iostream>
using namespace std;

int n;
long long dp[1001][10];
long long sum;

int main(){
    cin>>n;
    for(int i=0; i<10; i++){
        dp[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<10; k++){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    for(int i=0; i<10; i++){
        sum += dp[n][i];
        sum %= 10007;
    }
    cout<<sum;
}
