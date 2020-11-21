#include <iostream>
#include <string>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    
    long long Asum = 0;
    long long Bsum = 0;
    
    for(int i=0; i<a.length(); i++){
        if(a.at(i) != '0')    Asum += (int)a.at(i) - 48;
    }
    
    for(int i=0; i<b.length(); i++){
        if(b.at(i) != 0)    Bsum += (int)b.at(i) - 48;
    }
    cout<<Asum*Bsum<<"\n";
    
        }
