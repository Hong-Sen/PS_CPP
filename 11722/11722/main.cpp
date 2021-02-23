#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
vector<int> v;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    reverse(arr, arr+n);
    v.push_back(-1);
    for(int i=0; i<n; i++){
        if(arr[i] > v.back())   v.push_back(arr[i]);
        else{
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout<<v.size()-1;
}
