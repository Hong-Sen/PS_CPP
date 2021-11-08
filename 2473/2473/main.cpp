#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
long long arr[5005];
vector<long long> v;
long long sum = 5000000001;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    for(int i=0; i<n-2; i++){
        int start = i+1, end = n-1;
        while (start < end) {
            if(abs(arr[i] + arr[start] + arr[end]) < sum){
                sum = abs(arr[i] + arr[start] + arr[end]);
                v.clear();
                v.push_back(arr[i]);
                v.push_back(arr[start]);
                v.push_back(arr[end]);
            }
            if(arr[i] + arr[start] + arr[end] < 0) start++;
            else end--;
        }
    }
   
    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
}
