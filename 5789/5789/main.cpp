#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s.at(s.length()/2-1) == s.at(s.length()/2))    cout<<"Do-it"<<"\n";
        else    cout<<"Do-it-Not"<<"\n";
    }
   
    
}
