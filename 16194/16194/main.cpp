#include <iostream>
#include <vector>
using namespace std;

int N;
int p[10001];
int dp[10001];

int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>p[i];
        dp[i] = p[i];
    }
    for(int k=2; k<=N; k++) {
        for(int i=1; i<=k/2; i++) {
            dp[k] = min(dp[k], dp[i] + dp[k-i]);
        }
    }
    cout<<dp[N];
}
