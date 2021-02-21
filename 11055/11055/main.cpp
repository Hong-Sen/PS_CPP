#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];
int result;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    for(int i=0; i<n; i++){
        dp[i] = arr[i];
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i]){
                dp[i] = dp[j] + arr[i];
            }
        }
        if(result < dp[i])    result = dp[i];
    }
    cout<<result;
}
