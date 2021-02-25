#include <iostream>
using namespace std;

string s1,s2;
int dp[1001][1001];

int main(){
    cin>>s1>>s2;
    s1 = "0" + s1;
    s2 = "1" + s2;

    for(int i=1; i<s1.length(); i++){
        for(int j=1; j<s2.length(); j++){
            if(s1.at(i) == s2.at(j)){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[s1.length()-1][s2.length()-1];
}
