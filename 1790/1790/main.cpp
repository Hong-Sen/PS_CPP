#include <iostream>
using namespace std;

int N,K;

int getLength(int n){
    int length = 0;
    int cnt = 0;
    for(int i=1; i<=n; i*=10){
        cnt++;
        int start  = i;
        int end = i*10-1;
        if(end-1 > n)   end = n;
        length += (end-start+1)*cnt;
    }
    return length;
}

int main(){
    cin>>N>>K;
    if(getLength(N) < K){
        cout<<"-1";
        return 0;
    }
    int start = 1;
    int end = N;
    int idx;
    while (start <= end) {
        int mid = (start + end) / 2;
        int length = getLength(mid);
        if(length < K){
            start = mid+1;
        }
        else{
            idx = mid;
            end = mid-1;
        }
    }
    string result = to_string(idx);
    result = result[result.size()-1-(getLength(idx)-K)];
    cout<<result;
}

