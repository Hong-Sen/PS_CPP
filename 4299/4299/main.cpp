#include <iostream>
using namespace std;

int main(){
    double sum,sub;
    cin>>sum>>sub;
    double a,b;
    a = (sum+sub)/2;
    b = (sum-sub)/2;
    if((a != (int)a) || (b != (int)b) || a<0 || b<0){
        cout<<"-1\n";
        return 0;
    }
    else{
        if(a>b)
            cout<<(int)a<<" "<<(int)b<<"\n";
        else
            cout<<(int)b<<" "<<(int)a<<"\n";
    }
    
}
