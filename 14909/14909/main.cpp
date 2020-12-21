#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int cnt = 0;
    getline(cin,s);
    string temp;
    for(int i=0; i<s.length(); i++){
        if(s.at(i)!=' ') {
            temp+=s.at(i);
        }
        else if(s.at(i)==' '){
            if(temp.at(0)!='-' && temp.at(0)!='0') cnt++;
            temp = "";
        }
        if(i==s.length()-1){
            if(temp.at(0)!='-' && temp.at(0)!='0') cnt++;
        }
    }
    cout<<cnt;
}
