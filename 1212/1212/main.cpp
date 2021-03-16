#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    string binary = "";
    if(s=="0"){
        cout<<"0";
        return 0;
    }
    for(int i=0; i<s.length(); i++){
        char tmp = s.at(i);
        if(tmp == '0')  binary += "000";
        else if(tmp == '1') binary += "001";
        else if(tmp == '2') binary += "010";
        else if(tmp == '3') binary += "011";
        else if(tmp == '4') binary += "100";
        else if(tmp == '5') binary += "101";
        else if(tmp == '6') binary += "110";
        else if(tmp == '7') binary += "111";
    }
    for(int i=0; i<binary.length(); i++){
        if(binary.at(i) == '1'){
            binary.erase(0,i);
            break;
        }
    }
    cout<<binary;
}
