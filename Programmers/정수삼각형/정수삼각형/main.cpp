#include <string>
#include <vector>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    for(int i=triangle.size()-1; i>=0; i--){
        for(int j=0; j<triangle[i].size(); j++){
            if(i==triangle.size()-1){
                dp[i][j] = triangle[i][j];
                continue;
            }
            dp[i][j] = max(dp[i+1][j] + triangle[i][j], dp[i+1][j+1] + triangle[i][j]);
        }
    }
    
    return dp[0][0];
}
