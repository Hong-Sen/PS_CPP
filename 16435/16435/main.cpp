#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,h;
    vector<int> v;
    cin>>n>>h;
    for(int i=0; i<n; i++){
        int l;
        cin>>l;
        v.push_back(l);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        if(v[i] > h)    break;
        else    h++;
    }
    cout<<h;
}
