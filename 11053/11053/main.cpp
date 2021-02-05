#include <iostream>
#include <vector>
using namespace std;

int dp[1001];
int arr[1001];
int cnt;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    dp[0] = 1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
               
            }
        }
        if(cnt < dp[i]) cnt = dp[i];
    }
    if(cnt == 0) cout<<1;
    else    cout<<cnt;
    
}
