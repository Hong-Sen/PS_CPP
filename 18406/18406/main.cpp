#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int front=0,rear=0;
    for(int i=0; i<s.length(); i++){
        if(i<(s.length()/2))    front += s.at(i);
        else    rear += s.at(i);
    }
    if(front == rear)   cout<<"LUCKY\n";
    else    cout<<"READY\n";
}
