#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    
    int n,m;
    vector<int> v;
    cin>>n>>m;
    for(int i=0; i<n+m; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    
    for(int i=0; i<n+m; i++)
        cout<<v[i]<<" ";
    
    cout<<"\n";
}
