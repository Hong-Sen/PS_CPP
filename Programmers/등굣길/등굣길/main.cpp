#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles){
    for(int i=0; i<puddles.size(); i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    dp[1][1] =1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(dp[i][j] == -1) dp[i][j] = 0;
            else dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    return dp[n][m];
}

int main(){
    cout<<solution(4, 3, {{2,2}});
}
