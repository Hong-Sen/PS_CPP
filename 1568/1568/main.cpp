#include <iostream>
using namespace std;

int main(){
    int n,sing=0,i=1;
    cin>>n;
    while(n>0){
        if(n<i) i=1;
        n -= i;
        i++;
        sing++;
    }
    cout<<sing<<"\n";
}
