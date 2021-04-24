#include <iostream>
#include <cmath>
using namespace std;

int arr[10000000];

bool isPalindrome(int n){
    string s = to_string(n);
    for(int i=0; i<s.length()/2; i++){
        if(s.at(i) != s.at(s.length()-1-i)) return false;
    }
    return true;
}

int main(){
    int a,b;
    cin>>a>>b;
    if(b > 10000000)    b = 10000000;
    for(int i=2; i<=sqrt(b); i++){
        for(int j=i+i; j<=b; j+=i){
            if(j<a) continue;
            arr[j] = 1;
        }
    }
    for(int i=a; i<=b; i++){
        if(arr[i] == 0 &&  isPalindrome(i))     cout<<i<<"\n";
    }
    cout<<-1;
}
