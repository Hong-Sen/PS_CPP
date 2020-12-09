#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int u = stoi(s);
        int sum = u+n;
        string str = to_string(sum);
        bool reverse = true;
        for(int j=0; j<str.length()/2; j++){
            if(str.at(j) != str.at(str.length()-1-j)){
                reverse = false;
                break;
            }
        }
        if(reverse) cout<<"YES\n";
        else    cout<<"NO\n";
        
    }
}
