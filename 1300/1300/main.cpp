#include <iostream>
using namespace std;

int n,k,result;

int binarySearch(){
    int start = 1;
    int end = k;
    while (start <= end) {
        int mid = (start+end)/2;
        int cnt = 0;
        for(int i=1; i<=n; i++){
            cnt += min(mid/i, n);
        }
        if(cnt < k){
            start = mid + 1;
        }
        else{
            result = mid;
            end = mid - 1;
        }
    }
    return result;
}

int main(){
    cin>>n>>k;
    cout<<binarySearch();
}
