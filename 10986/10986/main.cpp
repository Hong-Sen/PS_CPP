//
//  main.cpp
//  10986
//
//  Created by 홍세은 on 2022/07/23.
//

#include <iostream>
using namespace std;

int N,M,x;
long long sum;
long long cnt[1000001];
long long result;

int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        cin>>x;
        sum += x;
        if(sum == 0){
            cnt[0]++;
            continue;
        }
        cnt[sum % M]++;
    }
    
    for(int i=0; i<M; i++) {
        result += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout<<cnt[0] + result;
}
