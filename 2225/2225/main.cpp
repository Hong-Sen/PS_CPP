#include <iostream>
using namespace std;

int n,k;
int dp[201][201];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    dp[0][0] = 1;
    
    for(int i=1; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int l=0; l<=j; l++){
                dp[i][j] += dp[i-1][l];
                dp[i][j] %= 1000000000;
            }
        }
    }
    cout<<dp[k][n];
}
