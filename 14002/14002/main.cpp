#include <iostream>
#include <vector>
using namespace std;

int n;
int maxDP;
int arr[1001];
int dp[1001];
vector<int> result;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    dp[0] = 1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j]+1)
                dp[i] = dp[j]+1;
        }
        if(dp[i] > maxDP)    maxDP = dp[i];
    }
    
    if(maxDP != 0){
        for(int i=n-1; i>=0; i--){
            if(maxDP == dp[i])  {
                result.push_back(arr[i]);
                maxDP--;
            }
        }
        cout<<result.size()<<"\n";
        for(int i=result.size()-1; i>=0; i--){
            cout<<result[i]<<" ";
        }
    }
    else{
        cout<<1<<"\n"<<arr[0];
    }
}
