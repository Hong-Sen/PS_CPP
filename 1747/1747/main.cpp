#include <iostream>
using namespace std;

int N;
int primeNum[1004001];

bool isPrimeNum(int n){
    if(primeNum[n] == 0)    return true;
    return false;
}

bool isPalindrome(int n){
    string s = to_string(n);
    int start = 0, end = s.size()-1;
    while (start < end) {
        if(s[start] == s[end]){
            start++;
            end--;
        }
        else return false;
    }
    return true;
}

int main(){
    cin>>N;
    primeNum[1] = 1;
    for(int i=2; i<=1004000; i++){
        if(primeNum[i]==1)   continue;
        for(int j=i+i; j<=1004000; j+=i){
            primeNum[j] = 1;
        }
    }
    while (N<=1004000) {
        if(isPrimeNum(N) && isPalindrome(N)){
            cout<<N;
            break;
        }
        N++;
    }
}
