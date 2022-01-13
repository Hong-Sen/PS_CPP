#include <iostream>
using namespace std;

int dp[1000001];
int before[1000001];

int main(){
    int n;
    cin>>n;
    for(int i=2; i<=n; i++){
        // 3번 연산(-1)
        dp[i] = dp[i-1] + 1;
        before[i] = i-1;
        // 1번 연산(/3)
        if(i%3==0 && dp[i] > dp[i/3]+1){
            dp[i] = dp[i/3] + 1;
            before[i] = i/3;
        }
        // 2번 연산(/2)
        if(i%2==0 && dp[i] > dp[i/2] + 1){
            dp[i] = dp[i/2] + 1;
            before[i] = i/2;
        }
    }
    cout<<dp[n]<<"\n";
    while (1) {
        cout<<n<<" ";
        n = before[n];
        if(n == 0) break;
    }
}

