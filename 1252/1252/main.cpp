#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int carry[83];

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length() < s2.length())   swap(s1,s2);
    s1 = '0' + s1;
    string tmp = "";
    for(int i=0; i<s1.length()-s2.length(); i++){
        tmp += '0';
    }
    s2 = tmp + s2;
    string result = "";
    for(int i=s1.length()-1; i>=1; i--){
        int a = (int)(s1.at(i)) - 48;
        int b = (int)(s2.at(i)) - 48;
        if(a + b + carry[i] == 0){
            result += "0";
        }
        else if(a + b + carry[i] == 1){
            result += "1";
        }
        else if(a + b + carry[i] == 2){
            result += "0";
            carry[i-1] = 1;
        }
        else if(a + b + carry[i] == 3){
            result += "1";
            carry[i-1] = 1;
        }
    }
    if(carry[0] == 1)   result += "1";
    reverse(result.begin(), result.end());
    int i = 0;
    while (result.at(i) == '0') {
        i++;
        if(i>=result.size()) break;
    }
    if(i != 0)  result.erase(0,i);
    if(result == "")    cout<<0;
    else    cout<<result;
}
