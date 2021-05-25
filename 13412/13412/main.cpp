#include <iostream>
using namespace std;

int cnt;

double gcd(int a, int b){
    while (b!=0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

double lcm(int a,int b){
    return a*b/gcd(a,b);
}

void solve(int n){
    double a = 1,b = n;
    while (a<=b) {
        if(gcd(a, b) == 1 && (b - (int)b == 0)){
            cnt++;
        }
        a++;
        b =  n/a;
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int x;
        cin>>x;
        cnt = 0;
        solve(x);
        cout<<cnt<<"\n";
    }
}
