//
//  main.cpp
//  2042
//
//  Created by 홍세은 on 2022/07/11.
//

#include <iostream>
#include <vector>
using namespace std;

int N,M,K;
long long a,b,c;
long long num[1000001];
long long tree[4000004];

long long init(int start, int end, int node) {
    if(start == end) return tree[node] = num[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

long long sum(int start, int end, int node, int left, int right) {
    // 범위 밖
    if(left > end || right < start) return 0;
    // 범위 안
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid+1, end, node*2+1, left,right);
}

void update(int start, int end, int node, int idx, long long value) {
    // 범위 밖
    if(idx < start || idx > end) return;
    // 범위 안에 있으면 트리 내려가면서 다른 원소도 수정
    tree[node] += value;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node*2, idx, value);
    update(mid+1, end, node*2+1, idx, value);
}

int main(){
    cin>>N>>M>>K;
    long long n;
    for(int i=1; i<=N; i++) {
        cin>>n;
        num[i] = n;
    }
    
    init(1,N,1);
    
    for(int i=0; i<M+K; i++) {
        cin>>a>>b>>c;
        if(a == 1) {
            long long value = c - num[b];
            num[b] = c;
            update(1, N, 1, b, value);
        }
        else {
            cout<<sum(1,N,1,b,c)<<"\n";
        }
    }
    
}
