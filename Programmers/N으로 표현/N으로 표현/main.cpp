#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<set<int>> dp(8);

int solution(int N, int number) {
    if(N == number) return 1;
    int plusNum = N;
    dp[0].insert(N);
    for(int k=1; k<8; k++){
        for(int i=0; i<k; i++){
            for(int j=k-i-1; j>=0; j--){
                for(int l: dp[i]){
                    for(int m: dp[j]){
                        dp[k].insert(l + m);
                        dp[k].insert(l * m);
                        if(l-m > 0) dp[k].insert(l - m);
                        if(m != 0) dp[k].insert(l / m);
                    }
                }
            }
        }
        plusNum = plusNum * 10 + N;
        dp[k].insert(plusNum);
        if(dp[k].count(number))  return k+1;
    }
    return -1;
}

int main(){
    cout<<solution(8,53);
}
