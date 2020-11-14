#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    
    for(int i=0; i<n; i++){
        cout<<v[i]<<"\n";
    }
    }
