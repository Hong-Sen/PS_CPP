//
//  main.cpp
//  1509
//
//  Created by 홍세은 on 2022/06/20.
//

#include <iostream>
#include <string>
#define INF 2502
using namespace std;

string str;
int result[2501];
bool dp[2501][2501];
bool flag;

bool isPalindrome(int i, int j) {
    if(str[i] == str[j]) {
        if(dp[i+1][j-1] || j-i == 1) return true;
    }
    return false;
}

int main(){
    cin>>str;
    str = " " + str;
    
    for(int k=0; k<str.size()-1; k++) {
        for(int i=1; i+k<str.size(); i++) {
            if(k == 0){
                dp[i][i] = true;
                continue;
            }
            if(isPalindrome(i, i+k)) dp[i][i+k] = true;
        }
    }

    result[0] = 0;
    for(int i=1; i<str.size(); i++) {
        result[i] = INF;
        for(int j=1; j<=i; j++) {
            if(dp[j][i]) {
                result[i] = min(result[i], result[j-1] + 1);
            }
        }
    }

    cout<<result[str.size()-1];
    
}
