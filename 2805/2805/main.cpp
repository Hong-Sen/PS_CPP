#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int v[1000001];

void binarysearch(int v[],long long n,long long m){
    long long start = 0;
    long long end = v[n-1];
    long long result = 0;
    while(end>=start){
        long long mid = (end+start)/2;
        long long sum = 0;
        for(int i=0;i<n;i++){
            if(v[i]>mid)
            sum += v[i] - mid;
        }
        if(sum>=m){
            if(result<mid)
                result = mid;
            start = mid+1; //기존의 이진탐색과는 반대로! v[i]-mid 니까!!
        }
        else if(sum<m){
            end = mid-1;
        }
    }
    cout<<result<<"\n";
}

int main(){
    long long n,m;
    
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    sort(v,v+n);
    binarysearch(v, n, m);
}
