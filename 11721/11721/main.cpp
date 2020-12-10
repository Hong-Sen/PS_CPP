#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i=0; i<s.length(); i++){
        if(i%10==9){
            cout<<s.at(i)<<"\n";
        }
        else    cout<<s.at(i);
    }
    cout<<"\n";
}
