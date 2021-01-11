#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int n,cnt = 0;
    cin>>s>>n;
    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        str += str;
        if(str.find(s)>=0 &&str.find(s)<=str.size())    cnt++;
    }
    cout<<cnt;
}
