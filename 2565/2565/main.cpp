#include <iostream>
#include <vector>
using namespace std;

int n,A,B,maxNum,result;;
int arr[501];
int dp[501];

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>A>>B;
        arr[A] = B;
        maxNum = max(maxNum,A);
        maxNum = max(maxNum,B);
    }
    dp[0] = 1;
    for(int i=1; i<=maxNum; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && dp[j]+1 > dp[i] && arr[j] != 0){
                dp[i] = dp[j]+1;
            }
        }
        result = max(result, dp[i]);
    }
    cout<<n - result;
}
