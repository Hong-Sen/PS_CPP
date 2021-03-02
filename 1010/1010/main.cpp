#include <iostream>
using namespace std;

int dp[32][32];

int main(){
    int t;
    cin>>t;
    for(int i=1; i<31; i++){
        dp[1][i] = i;
    }
    for(int i=2; i<=30; i++){
        for(int j=i; j<=30; j++){
            for(int k=1; k<j; k++){
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    for(int i=0; i<t; i++){
        int n,m;
        cin>>n>>m;
        cout<<dp[n][m]<<"\n";
    }
}
