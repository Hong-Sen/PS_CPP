#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100001];
int dp[100001];

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int tmp = arr[0];
    int result = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] < tmp+arr[i]){
            dp[i] = tmp+arr[i];
            tmp += arr[i];
        }
        else{
            tmp = arr[i];
            dp[i] = tmp;
        }
        result = max(dp[i], result);
    }
    
    cout<<result;
    
}
