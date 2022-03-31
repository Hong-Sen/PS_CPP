//
//  main.cpp
//  1182_2
//
//  Created by 홍세은 on 2022/03/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,s,x;
vector<int> v;
int result;

void dfs(int idx, int sum){
    sum += v[idx];
    if(idx == n) return;
    if(sum == s) result++; // 다음 원소가 0일 수 있으니 return 생략
    dfs(idx+1, sum - v[idx]);
    dfs(idx+1, sum);
}

int main(){
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    
    sort(v.begin(),v.end());
    dfs(0, 0);
    cout<<result;
}
