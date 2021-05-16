#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    
    bool flag = prev_permutation(v.begin(), v.end());
    if(flag){
        for(int i=0; i<n; i++)
            cout<<v[i]<<" ";
    }
    else{
        cout<<"-1";
    }
}
