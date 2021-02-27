#include <iostream>
using namespace std;

int arr[11];
int cnt;

int main(){
    int n,k;
    cin>>n>>k;
    int index = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i] <= k)  index = i;
    }
    while(k!=0){
        cnt += k/arr[index];
        k %= arr[index];
        index--;
    }
    cout<<cnt;
}
