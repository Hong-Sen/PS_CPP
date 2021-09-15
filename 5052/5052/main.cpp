#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int j=0; j<t; j++){
        cin>>n;
        vector<string> v;
        bool flag = true;
        for(int i=0; i<n; i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        for(int i=0; i<n-1; i++){
            if(v[i+1].find(v[i]) == 0){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
