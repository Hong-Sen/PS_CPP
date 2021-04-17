#include <iostream>
using namespace std;

int arr[2001];
int dp[2001];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[n-i-1];
    }
    
    int max = 0;
    dp[0] = 1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && dp[i] <= dp[j])   dp[i] = dp[j] + 1;
        }
        max = (max < dp[i]) ? dp[i] : max;
    }
    if(max == 0)    cout<<"0";
    else    cout<<n-max;
    
}
