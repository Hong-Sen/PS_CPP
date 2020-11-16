#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        reverse(s.begin(), s.end());
        long long x = stol(s);
        v.push_back(x);
    }
    
    sort(v.begin(),v.end());

    for(int i=0; i<n; i++)
        cout<<v[i]<<"\n";
}
