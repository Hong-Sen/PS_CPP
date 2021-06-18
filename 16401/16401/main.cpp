#include <iostream>
#include <algorithm>
using namespace std;

int m,n;
int snack[1000001];

bool getSnack(int k){
    int cnt = 0;
    for(int i=0; i<n; i++){
       cnt += snack[i]/k;
    }
    if(cnt >= m) return true;
    else    return false;
}

int main(){
    cin>>m>>n;
    int high = 0, low = 1;
    for(int i=0; i<n; i++){
        cin>>snack[i];
        high = max(snack[i], high);
    }
    int result = 0;
    while (low <= high) {
        int mid = (low + high)/2;
        if(getSnack(mid)){
            result = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<result;
}
