#include <iostream>
#include <string>
using namespace std;

int main(){
    string s = "DCBAE";
    for(int i=0; i<3; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<s.at(a+b+c+d)<<"\n";
    }
}
