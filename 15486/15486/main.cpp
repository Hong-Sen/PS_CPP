//
//  main.cpp
//  15486
//
//  Created by 홍세은 on 2022/07/14.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> T;
vector<int> P;
int dp[15000001];

int main(){
    cin>>N;
    for(int i=0; i<N; i++) {
        int t,p;
        cin>>t>>p;
        T.push_back(t);
        P.push_back(p);
    }
    
    dp[T[0]] = P[0];
    
    for(int i=1; i<N; i++) {
        dp[i] = max(dp[i-1], dp[i]);
        dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
    }
    
    cout<<max(dp[N], dp[N-1]);
}
