#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

string changeKNum(int n, int k) {
    int value = n;
    stack<int> st;
    while(value != 0) {
        st.push(value % k);
        value /= k;
    }
    
    string str = "";
    while(!st.empty()){
        str += to_string(st.top());
        st.pop();
    }
    return str;
}

bool isPrime(long long n) {
    if(n == 1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string KNum = changeKNum(n,k) + '0';
    string tmp = "";
    for(int i=0; i<KNum.size(); i++){
        if(KNum[i] == '0'){
            long long num = 0;
            if(tmp != ""){
                num = stoll(tmp);
                if(isPrime(num)) answer++;
            }
            tmp = "";
            cout<<i<<" "<<num<<" "<<answer<<"\n";
            continue;
        }
        tmp += KNum[i];
    }
    return answer;
}
