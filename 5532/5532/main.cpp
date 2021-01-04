#include <iostream>
using namespace std;

int main(){
    int l,a,b,c,d;
    cin>>l>>a>>b>>c>>d;
    int k=0,m=0;
    if(a%c != 0)    k = a/c+1;
    else    k = a/c;
    if(b%d != 0)    m = b/d+1;
    else    m = b/d;
    
    if(k>=m)    cout<<l-k;
    else    cout<<l-m;
    
}
