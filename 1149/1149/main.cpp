#include <iostream>
#include <algorithm>
#define min(x,y) (x>y ? y : x)
using namespace std;

int arr[1000][3];
int dp[1000][3];

int main(){
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        if(i==0){
            dp[0][0] = arr[0][0];
            dp[0][1] = arr[0][1];
            dp[0][2] = arr[0][2];
        }
        else{
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
        }
        
    }
    
    sort(dp[n-1],dp[n-1]+3);
    cout<<dp[n-1][0];
    
}
