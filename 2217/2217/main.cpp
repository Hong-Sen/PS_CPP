//
//  main.cpp
//  2217
//
//  Created by 홍세은 on 2022/07/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
long long result;

int main(){
    cin>>N;
    int x;
    for(int i=0; i<N; i++) {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i=0; i<N; i++) {
        if(result < v[i] * (i+1)) result = v[i] * (i+1);
    }
    
    cout<<result;
}
