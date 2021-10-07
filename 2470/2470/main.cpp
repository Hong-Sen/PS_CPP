#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[100001];
int liquid1,liquid2;

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr,arr+n);
    
    int s = 0;
    int e = n-1;
    int result = 2000000001;
    while (s<e) {
        int sum = arr[s] + arr[e];
        if(abs(sum) < result){
            result = abs(sum);
            liquid1 = arr[s];
            liquid2 = arr[e];
        }
        if(sum == 0)    break;
        if(sum < 0) s++;
        else    e--;
    }
    cout<<liquid1<<" "<<liquid2;
}
