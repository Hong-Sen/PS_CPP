#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001];
int dp1[1001];
int dp2[1001];
int n;
int result;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    dp1[0] = 1;
    for(int i=1; i<n; i++){
        dp1[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && dp1[i] < dp1[j] + 1)  dp1[i] = dp1[j] + 1;
        }
    }
    
    dp2[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        dp2[i] = 1;
        for(int j=n-1; j>=i; j--){
            if(arr[i] > arr[j] && dp2[i] < dp2[j]+1)    dp2[i] = dp2[j] + 1;
        }
    }
    
    for(int i=0; i<n; i++){
        if(result < dp1[i]+dp2[i])  {
            result = dp1[i]+dp2[i];
    }
    }
    cout<<result-1;
}
