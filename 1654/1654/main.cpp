#include <iostream>
#include <algorithm>
using namespace std;

long long LAN[10001];

void binarySearch(int k, int n, long long LAN[] ){
    long long start = 1; //start를 0으로 두고 실행했더니 런타임에러가 났다. 0으로 나눌 순 없으니까!!! 한참 찾았네,,
    long long end = LAN[k-1];
    long long max = 0;
    
    while(end>=start){
        long long mid = (start+end)/2;
        long long cnt = 0;
        for(int i=0;i<k;i++){
            cnt += LAN[i]/mid;
        }
        
        if(cnt>=n){
            start = mid+1;
            if(max<mid)
                max = mid;
        }
        else{
            end = mid-1;
        }
    }
    
    cout<<max<<"\n";
}

int main(){

    int k,n;
    cin>>k>>n;
    for(int i=0;i<k;i++){
        cin>>LAN[i];
    }
    
    sort(LAN, LAN+k);
    
    binarySearch(k, n, LAN);
    
    
}
