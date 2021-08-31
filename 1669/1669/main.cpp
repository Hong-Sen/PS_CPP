#include <iostream>
#include <cmath>
using namespace std;

int n;
int rt;
int dp[1000001];

int main(){
    cin>>n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
  
    for(int i=4; i<=n; i++){
        rt = sqrt(i);
        dp[i] = 100001;
        for(int j = rt; j>=2; j--){
            dp[i] = min(dp[i-(j*j)] + 1, dp[i]);
        }
    }
    cout<<dp[n]<<"\n";
    
}
