#include <iostream>
#include <string>
using namespace std;

int main(){
    for(int i=0; i<100; i++){
        string s;
        getline(cin, s);
        if(s.length() == 0) return 0;
        int a=0,A=0,num=0,space=0;
        for(int j=0; j<s.length(); j++){
            char c = s.at(j);
            if(c == ' ')    space++;
            else if(c >= 'a')    a++;
            else if(c >= 'A')   A++;
            else    num++;
        }
        cout<<a<<" "<<A<<" "<<num<<" "<<space<<"\n";
    }
}
