#include <iostream>
using namespace std;

int main(){
    for(int i=0; i<3; i++){
        int x,zero=0;
        cin>>x;
        if(x==0)    zero++;
        cin>>x;
        if(x==0)    zero++;
        cin>>x;
        if(x==0)    zero++;
        cin>>x;
        if(x==0)    zero++;
        
        if(zero==0) cout<<"E\n";
        if(zero==1) cout<<"A\n";
        if(zero==2) cout<<"B\n";
        if(zero==3) cout<<"C\n";
        if(zero==4) cout<<"D\n";
    }
}
