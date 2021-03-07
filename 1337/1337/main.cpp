#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    sort(arr, arr+n);
   
    int cnt = 1;
    int index = 0;
    int max = 1;
    for(int i=1; i<n; i++){
        cnt++;
        while(arr[i] - arr[index] > 4){
            index++;
            cnt--;
        }
        if(max < cnt)   max = cnt;
    }
    if(max > 5) max = 5;
    cout<<5-max;
}
