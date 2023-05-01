#include <iostream>
using namespace std;

int T, idx;
string s;

int main(){
    cin>>T;
    while (T--) {
        cin>>s;
        string str = "";
        for(int i=0; i<s.size(); i++) {
            str += s[i];
            string tmp = s;
            if(s.substr(i+1).find(str) == 0 && s.substr(i+1+str.size()).find(str) == 0) break;
        }
        cout<<"#"<<++idx<<" ";
        if(str.size() > 10) cout<<"0\n";
        else cout<<str.size()<<"\n";
    }
}
