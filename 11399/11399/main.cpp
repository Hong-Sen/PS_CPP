#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    
    for(int i=0; i<n; i++){
        int p;
        cin>>p;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    int sum = v[0];
    for(int i=1;i<n;i++){
        v[i] += v[i-1];
        sum += v[i];
    }
    cout<<sum<<"\n";
    
}
