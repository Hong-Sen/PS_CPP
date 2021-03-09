#include <iostream>
using namespace std;

int MAX(int x,int y, int z){
    if(x>=y && x>=z)  return x;
    else if(y>=x && y>=z) return y;
    else if(z>=x && z>=y) return z;
    else    return 0;
}

int main(){
    int n;
    int arr[10001];
    int dp[10001];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = MAX(arr[0] + arr[2], arr[1] + arr[2], dp[1]);
    for(int i=3; i<n; i++){
        dp[i] = MAX(arr[i] + arr[i-1] + dp[i-3], arr[i] + dp[i-2], dp[i-1]);
    }
    int result = 0;
    for(int i=0; i<n; i++)
    result = max(result,dp[i]);
    cout<<result;
}

