//n==10000 일때 long long범위 초과
//string으로 형변환시켜 계산
#include <iostream>
#include <algorithm>
using namespace std;

string dp[10001];

string calc(string s1, string s2){
    string result;
    bool carry = false;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    //s1,s2길이 맞추기
    while(s1.length() > s2.length()){
        s2 += "0";
    }
    while (s1.length() < s2.length()) {
        s1 += "0";
    }
    for(int i=0; i<s1.length(); i++){
        int sum = 0;
        if(!carry){
            sum = (int)s1.at(i) + (int)s2.at(i) - 96;
        }
        else{
            sum = (int)s1.at(i) + (int)s2.at(i) + 1 - 96;
            carry = false;
            
        }
        if(sum > 9){
            carry = true;
            sum %= 10;
        }
        result += to_string(sum);
        if(i==s1.length()-1){
            if(carry)   result += "1";
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    int n;
    cin>>n;
    dp[0] = "0";
    dp[1] = "1";
    for(int i=2; i<=n; i++){
        dp[i] = calc(dp[i-1],dp[i-2]);
    }
    cout<<dp[n];
    
}
