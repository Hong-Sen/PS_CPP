//
//  main.cpp
//  6588
//
//  Created by 홍세은 on 2023/01/26.
//

#include <iostream>
#include <cmath>
using namespace std;

int n = 1;
int a,b;
bool flag;
bool notPrimeNumber[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    notPrimeNumber[0] = true;
    notPrimeNumber[1] = true;
    for(int i=2; i<=sqrt(1000000); i++) {
        if(!notPrimeNumber[i]) {
            for(int j=i*i; j<=1000000; j+=i) {
                notPrimeNumber[j] = true;
            }
        }
    }
    
    while (1) {
        cin>>n;
        if(n == 0) break;
        flag = false;
        for(int i=n-2; i>=n/2; i--) {
            b = i;
            a = n - i;
            if(!notPrimeNumber[b] && !notPrimeNumber[a]){
                flag = true;
                break;
            }
        }
        if(flag) cout<<n<<" = "<<a<<" + "<<b<<"\n";
        else cout<<"Goldbach's conjecture is wrong."<<"\n";
    }
}
