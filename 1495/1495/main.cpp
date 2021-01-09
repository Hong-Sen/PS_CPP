#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,s,m;
    int arr[101];
    bool dp[101][1001] = {false,};
    cin>>n>>s>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i+1];
    }
    dp[0][s] = true;
    for(int i=1;i<=n; i++){
        for(int j=0; j<=m; j++){
            if(dp[i-1][j]){
                if(j-arr[i] >= 0 && j-arr[i] <= m)  {
                    dp[i][j-arr[i]] = true;
                }
                if(j+arr[i] >= 0 && j+arr[i] <= m){
                    dp[i][j+arr[i]] = true;
                }
            }
        }
    }
    int flag = -1;
    for(int i=m; i>=0; i--){
        if(dp[n][i])    {
            flag = i;
            break;
        }
    }
    cout<<flag;
}
