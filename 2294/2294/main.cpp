#include <iostream>
using namespace std;

int n,k,minN = 100001;
int arr[101];
int dp[10001];
int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<=k; i++)
        dp[i] = 100001;
    
    for(int i=0; i<n; i++){
        for(int j=arr[i]; j<=k; j++){
            dp[j] = min(dp[j], dp[j-arr[i]] + 1);
            if(j==k)    minN = min(minN,dp[j]);
        }
    }
    if(minN == 100001)   cout<<"-1";
    else     cout<<minN;
}
