#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int n1, int n2){
    return n1 > n2;
}

int main(){
    int n;
    cin>>n;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(),cmp);
  
    int s = 0;
    for(int i=0;i<n;i++){
        s += a[i] * b[i];
    }
    
    cout<<s<<"\n";
    
}
