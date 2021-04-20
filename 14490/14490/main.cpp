#include <iostream>
#include <string>
using namespace std;

int gcd(int a,int b){
    int r;
    while (b!=0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    string s;
    cin>>s;
    string n1,n2;
    bool flag = true;
    for(int i=0; i<s.length(); i++){
        if(s.at(i) == ':'){
            flag = false;
            continue;
        }
        if(flag)    n1 += s.at(i);
        else   n2 += s.at(i);
    }
    
    int a = stoi(n1);
    int b = stoi(n2);
    int gcdNum = gcd(a, b);
    cout<<a/gcdNum<<":"<<b/gcdNum<<"\n";
}
