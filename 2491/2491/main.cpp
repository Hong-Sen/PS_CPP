#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp1[100001];
int dp2[100001];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    //연속증가수열
    dp1[0] = 1;
    for(int i=1; i<n; i++){
        if(arr[i] >= arr[i-1])   dp1[i] = dp1[i-1]+1;
        else    dp1[i] = 1;
    }
    
    //연속감소수열
    dp2[0] = 1;
    for(int i=1; i<n; i++){
        if(arr[i] <= arr[i-1])   dp2[i] = dp2[i-1]+1;
        else    dp2[i] = 1;
    }
    sort(dp1, dp1+n);
    sort(dp2, dp2+n);
    
    cout<<max(dp1[n-1], dp2[n-1]);
}
