#include <iostream>
using namespace std;

int main(){
    int n,T,sum=0,cnt=0;
    int arr[50];
    cin>>n>>T;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
        if(sum <= T)    cnt++;
    }
    cout<<cnt;
}
