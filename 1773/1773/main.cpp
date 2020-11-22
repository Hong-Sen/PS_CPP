#include <iostream>
#include <algorithm>
using namespace std;

bool isvisted[2000000];
int arr[100];

int main(){
    int n,t;
    cin>>n>>t;
    int sum = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    
    for(int i=0; i<n; i++){
        int x = arr[i];
        if(isvisted[arr[i]])    continue; //이게 시간줄이는 포인트!!! 
        while(x <= t){
            if(!isvisted[x]){
                sum ++;
                isvisted[x] = true;
            }
            x += arr[i];
        }
    }
    
    cout<<sum<<"\n";
}
