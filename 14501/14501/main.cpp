#include <iostream>
#include <algorithm>
using namespace std;

int n;
int tp[20][2];
int dp[20];

int main(){
    cin>>n;
    int t,p;
    for(int i=1; i<=n; i++){
        cin>>t>>p;
        tp[i][0] = t;
        tp[i][1] = p;
    }
    
    for(int i=n; i>0; i--){
        if(tp[i][0] + i - 1 <= n){
            dp[i] = max(dp[i+tp[i][0]] + tp[i][1], dp[i+1]);
        }
        else{
            dp[i] = dp[i+1];
        }
    }
    cout<<dp[1];
}
