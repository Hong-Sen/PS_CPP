//
//  main.cpp
//  17425
//
//  Created by 홍세은 on 2022/12/31.
//

#include <iostream>
using namespace std;
int T,n;
long long result[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=1; i<=1000000; i++) {
        for(int j=i; j<=1000000; j+=i) {
            result[j] += i;
        }
    }
    
    for(int i=2; i<=1000000; i++) {
        result[i] += result[i-1];
    }
    
    cin>>T;
    while (T--) {
        cin>>n;
        cout<<result[n]<<"\n";
    }
}
