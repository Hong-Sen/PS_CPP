#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main(){
    int n;
    int result = 1;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    dp[0] = 1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i] && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
        if(result < dp[i])  result = dp[i];
    }
    cout<<result;
}
