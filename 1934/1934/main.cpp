#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int a,b;
        cin>>a>>b;
        if(a>b)  swap(a, b);
        int m = b;
        while(1){
            if(b%a==0)  break;
            b += m;
        }
        cout<<b<<"\n";
    }
}
