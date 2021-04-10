#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];
int n;

void solve(){
    for(int i=1; i<n; i++){
        int max = -1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                if(max < dp[j])    max = dp[j];
            }
        }
        if(max > -1)  dp[i] = max+1;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    solve();
    int max = 0;
    for(int i=0; i<n; i++){
        if(max < dp[i]) max = dp[i];
    }
    cout<<max + 1<<"\n";
}
