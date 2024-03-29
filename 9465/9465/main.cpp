#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int t,n;
int arr[2][100001];
int dp[2][100001];

int solution(){
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    dp[0][1] = arr[0][1] + dp[1][0];
    dp[1][1] = arr[1][1] + dp[0][0];
    
    for(int i=2; i<n; i++){
        dp[0][i] = arr[0][i] + max(dp[1][i-2], dp[1][i-1]);
        dp[1][i] = arr[1][i] + max(dp[0][i-2], dp[0][i-1]);
    }
    return max(dp[0][n-1], dp[1][n-1]);
}

int main(){
    cin>>t;
    while (t--) {
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }
        cout<<solution()<<"\n";
    }
}
