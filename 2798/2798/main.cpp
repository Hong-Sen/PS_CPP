#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
        
    sort(arr.begin(),arr.end());
   
    int sum = 0;
    vector<int>v;
    for(int i=(n-1); i>=2; i--){
        for(int j=(i-1); j>=1; j--){
            for(int l=(j-1); l>=0; l--){
                if((arr[i]+arr[j]+arr[l])<=m){
                    sum = arr[i]+arr[j]+arr[l];
                    v.push_back(sum);
                }
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    cout<<v[v.size()-1]<<'\n';
}
