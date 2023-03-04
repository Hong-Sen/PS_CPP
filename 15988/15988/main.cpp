#include <iostream>
using namespace std;

int tc, n;
long long dp[1000001];

int main() {
    cin>>tc;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    while(tc--) {
        cin>>n;
        for(int i=4; i<=n; i++) {
            if(dp[i] != 0) continue;
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
        }
        cout<<dp[n]<<"\n";
    }
}
