#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,w,v;
vector<pair<int, int>> arr; //w,v
int dp[102][100001];

int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>w>>v;
            arr.push_back({w,v});
    }
    arr.push_back({0,0});
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++){
        for(int j=1; j<=k; j++){
            if(i==0)    dp[i][j] = 0;
            else if(j>=arr[i].first){
                dp[i][j] = max(dp[i-1][j], arr[i].second + dp[i-1][j-arr[i].first]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][k];
}
